#include <bits/stdc++.h>

using namespace std;

class Transaction
{
public:
    string description;
    double amount;
    bool expense;

    Transaction(const string &desc, double amt, bool exp)
    {
        description = desc;
        amount = amt;
        expense = exp;
    }
};

class FinancialHelper
{
private:
    vector<Transaction> transactions;

public:
    void add(const string &description, double amount, bool expense);
    void dsply() const;
    double res_exp() const;
    double res_incm() const;
    double res_save() const;
    void res_savings_goal(double month_goal) const;
};

void FinancialHelper::add(const string &description, double amount, bool expense)
{
    transactions.emplace_back(description, amount, expense);
}

double FinancialHelper::res_exp() const
{
    double total = 0;
    for (const auto &transaction : transactions)
    {
        if (transaction.expense)
        {
            total += transaction.amount;
        }
    }
    return total;
}

double FinancialHelper::res_incm() const
{
    double total = 0;
    for (const auto &transaction : transactions)
    {
        if (!transaction.expense)
        {
            total += transaction.amount;
        }
    }
    return total;
}

double FinancialHelper::res_save() const
{
    return res_incm() - res_exp();
}

void FinancialHelper::dsply() const
{
    double total_incm = res_incm();
    double total_expns = res_exp();
    double net_savings = res_save();

    cout << fixed << setprecision(2);
    cout << "Total Income: " << total_incm << endl;
    cout << "Total Expenses: " << total_expns << endl;
    cout << "Net Savings: " << net_savings << endl;
}

void FinancialHelper::res_savings_goal(double month_goal) const
{
    double net_savings = res_save();
    double savings_need = month_goal - net_savings;
    if (savings_need <= 0)
    {
        cout << "Mothly savings goal reached" << endl;
    }
    else
    {
        double daily_goal = savings_need / 30; 
        cout << "You need to save " << daily_goal << " per day to reach your monthly goal of "<< month_goal << endl;
    }
}

int main()
{
    FinancialHelper helper;
    int choice;

    do
    {
        cout<<endl;
        cout << "Financial Helper\n";
        cout << "1. Add Income\n";
        cout << "2. Add Expense\n";
        cout << "3. Display Summary\n";
        cout << "4. Calculate Daily Savings Goal\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout<<endl<<endl<<endl<<endl;

        if (choice == 1)
        {
            string description;
            double amount;
            cout << "Enter description: ";
            cin.ignore();
            getline(cin, description);
            cout << "Enter income amount: ";
            cin >> amount;
            helper.add(description, amount, false);
        }
        else if (choice == 2)
        {
            string description;
            double amount;
            cout << "Enter description: ";
            cin.ignore();
            getline(cin, description);
            cout << "Enter expense amount: ";
            cin >> amount;
            helper.add(description, amount, true);
        }
        
        else if (choice == 3)
        {
            helper.dsply();
        }
        else if (choice == 4)
        {
            double month_goal;
            cout << "Enter monthly savings goal: ";
            cin >> month_goal;
            helper.res_savings_goal(month_goal);
        }
    } while (choice != 5);

    return 0;
}
