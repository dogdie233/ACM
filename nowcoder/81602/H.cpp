#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <memory>
#include <cstring>
#include <algorithm>
#include <any>
#include <set>

using namespace std;

class Table
{
public:
    vector<string> head;
    vector<vector<string>> data;

    Table() {}
    Table(const Table& table) : head(table.head), data(table.data) {}
};

stack<any> calStack;
Table table;

template<typename T> T popCalStack()
{
    T value = any_cast<T>(calStack.top());
    calStack.pop();
    return value;
}

class Command
{
public:
    virtual void execute() = 0;
    virtual void print() = 0;
    virtual void undo() = 0;
};

class InsertCommand : public Command
{
public:
    void execute()
    {
        int n = table.head.size();
        table.data.push_back(vector<string>(n));
        for (int i = n - 1; i >= 0; i--)
            table.data.back()[i] = popCalStack<string>();
    }

    void print()
    {
    }

    void undo()
    {
        table.data.pop_back();
    }
};

class SelectCommand : public Command
{
public:
    vector<string> result;

    void execute()
    {
        string value = popCalStack<string>();
        string name = popCalStack<string>();
        string outputName = popCalStack<string>();
        int id = find(table.head.begin(), table.head.end(), name) - table.head.begin();
        int outputId = find(table.head.begin(), table.head.end(), outputName) - table.head.begin();

        result.clear();
        for (int i = 0; i < table.data.size(); i++)
        {
            if (table.data[i][id] == value)
                result.push_back(table.data[i][outputId]);
        }
        calStack.push(result);
    }

    void print()
    {
        cout << result.size() << '\n';
        if (result.size() == 0)
            return;
        cout << result.front() << '\n';
        cout << result[(result.size() - 1) / 2] << '\n';
        cout << result.back() << '\n';
    }

    void undo()
    {
    }
};

class DeleteCommand : public Command
{
    vector<pair<int, vector<string>>> removed;

    void execute()
    {
        string value = popCalStack<string>();
        string name = popCalStack<string>();
        int id = find(table.head.begin(), table.head.end(), name) - table.head.begin();

        for (int i = table.data.size() - 1; i >= 0; i--)
        {
            if (table.data[i][id] == value)
            {
                removed.push_back({ i, table.data[i] });
                table.data.erase(table.data.begin() + i);
            }
        }
    }

    void print()
    {
        cout << removed.size() << '\n';
    }

    void undo()
    {
        for (int i = removed.size() - 1; i >= 0; i--)
            table.data.insert(table.data.begin() + removed[i].first, removed[i].second);
    }
};

class SelectInCommand : public Command
{
    vector<string> result;

    void execute()
    {
        vector<string> valueSet = popCalStack<vector<string>>();
        string name = popCalStack<string>();
        string outputName = popCalStack<string>();
        int id = find(table.head.begin(), table.head.end(), name) - table.head.begin();
        int outputId = find(table.head.begin(), table.head.end(), outputName) - table.head.begin();

        result.clear();
        for (int i = 0; i < table.data.size(); i++)
        {
            for (int j = 0; j < valueSet.size(); j++)
            {
                if (table.data[i][id] == valueSet[j])
                {
                    result.push_back(table.data[i][outputId]);
                    break;
                }
            }
        }
        calStack.push(result);
    }

    void print()
    {
        cout << result.size() << '\n';
        if (result.size() == 0)
            return;
        cout << result.front() << '\n';
        cout << result[(result.size() - 1) / 2] << '\n';
        cout << result.back() << '\n';
    }

    void undo() {}
};

class DeleteInCommand : public Command
{
    vector<pair<int, vector<string>>> removed;

    void execute()
    {
        vector<string> value = popCalStack<vector<string>>();
        string name = popCalStack<string>();
        int id = find(table.head.begin(), table.head.end(), name) - table.head.begin();

        for (int i = table.data.size() - 1; i >= 0; i--)
        {
            for (int j = 0; j < value.size(); j++)
            {
                if (table.data[i][id] == value[j])
                {
                    removed.push_back({ i, table.data[i] });
                    table.data.erase(table.data.begin() + i);
                    break;
                }
            }
        }
    }

    void print()
    {
        cout << removed.size() << '\n';
    }

    void undo()
    {
        for (int i = removed.size() - 1; i >= 0; i--)
            table.data.insert(table.data.begin() + removed[i].first, removed[i].second);
    }
};

class Parser
{
public:
    void parse(vector<shared_ptr<Command>>& commands, const string& line)
    {
        while (!calStack.empty())
            calStack.pop();
        size_t pos = 0;
        internal_parse(commands, line, pos);
    }

    shared_ptr<Command> make_command(const string& cmdName)
    {
        if (cmdName == "insert")
            return make_shared<InsertCommand>();
        else if (cmdName == "select")
            return make_shared<SelectCommand>();
        else if (cmdName == "delete")
            return make_shared<DeleteCommand>();
        else if (cmdName == "select_in")
            return make_shared<SelectInCommand>();
        else if (cmdName == "delete_in")
            return make_shared<DeleteInCommand>();
        throw runtime_error("unknown command " + cmdName);
    }

    void internal_parse(vector<shared_ptr<Command>>& commands, const string& str, size_t& pos)
    {
        size_t start = pos;
        while (pos < str.size())
        {
            if (str[pos] == '(')
            {
                auto pCommand = make_command(str.substr(start, pos - start));
                internal_parse(commands, str, ++pos);
                pCommand->execute();
                commands.push_back(pCommand);
                start = pos;
                continue;
            }
            if (str[pos] == ')')
            {
                if (pos - start != 0)
                    calStack.push(str.substr(start, pos - start));
                pos++;
                return;
            }
            if (str[pos] == ',')
            {
                if (pos - start != 0)
                    calStack.push(str.substr(start, pos - start));
                start = ++pos;
                continue;
            }
            pos++;
        }
    }
};

int main()
{
    int n, q;
    cin >> n >> q;
    table.head.resize(n);
    for (int i = 0; i < n; i++)
        cin >> table.head[i];

    bool isInScope = false;
    vector<shared_ptr<Command>> commands;
    for (int i = 0; i < q; i++)
    {
        string line;
        cin >> line;
        if (!isInScope)
        {
            if (line == "begin()")
            {
                isInScope = true;
                commands.clear();
                continue;
            }
        }
        else
        {
            if (line == "commit()")
            {
                isInScope = false;
            }
            else if (line == "abort()")
            {
                for (int j = commands.size() - 1; j >= 0; j--)
                    commands[j]->undo();
                isInScope = false;
            }
            else
            {
                Parser parser;
                parser.parse(commands, line);
                commands.back()->print();
            }
        }
    }
}