#include <bits/stdc++.h>
using namespace std;

// declearing data
int regester[20][5];
string names [20][5];
string stait [20][5];
int countp[20];

void add_patient()
{
    int special,status;
    int flag = 1;
    string name;
    cout << "enter specialization, name, status : " << endl;
    cin >> special >> name >> status;

    //cheking for available place
    for (int i = 0; i < 5; i++)
        {   
            if (regester[special][i] == -1)
            {
                flag = 0;
            }
        }
    if (flag)
    {
        cout << "Sorry the specialization is full" << endl;
        return;
    }
    else // adding patient
    {
    if (!status) // regular
    {
        for (int i = 0; i < 5; i++)
        {   
            if (regester[special][i] == -1)
            {
                regester[special][i] = status;
                names[special][i] = name;
                countp[special]++;
                stait[special][i] = "regular";
                break;
            }
        }

    }
    else //urgent
    {
        for (int i = countp[special]; i > 0; i--)
        {   
            regester[special][i] = regester[special][i-1];
            names[special][i] = names[special][i-1];
            stait[special][i] = stait[special][i-1];
        }
        regester[special][0] = status;
        names[special][0] = name;           
        countp[special]++;
        stait[special][0] = "urgent";
    }

}
}


void print_patients()
{
    for (int i = 0; i < 20; i++)
    {  
        if (regester[i][0] == -1)
        continue;
        else
        {
        cout << "there are " << countp[i] << " patients in specialization " << i << endl;
        for (int  j = 0; j < countp[i]; j++)
        {
            cout << names[i][j] << "  " << stait[i][j] << endl;
        }
        }
    }

}

void next_patient()
{
    int special;
    cout << "Enter Specialization : ";
    cin >> special;
    if (regester[special][0] == -1)
    cout << "No patients at the moment. Have rest, Dr" << endl;
    else
    {
        cout << names[special][0] << " please go with the Dr" << endl;
        for (int i = 0; i < 4; i++)
        {
            names[special][i] = names[special][i+1];
            regester[special][i] = regester[special][i+1];
        }
        countp[special]--;
    }

    
}

int main()
{
    // initializing regestration system aand number of patients
    for (int i = 0; i < 20; i++)
    {
        countp[i]=0;
        for (int j = 0; j < 5; j++)
        {
            regester[i][j] = -1; // not occupied
        }
        
    }

    while (true)
    {
        cout << "Enter your choice :" << endl;
        int choice;
        cin >> choice;
        if (!(choice >= 1 && choice <= 4))
        {
            cout << "Invalid input please try again." << endl;
            continue;
        }
        else
        {
            switch (choice)
            {
            case 1:
            {
                add_patient();
                break;
            }
            case 2:
            {
              print_patients();
                break;
            }
            case 3:
            {
                next_patient();
                break;
            }
            case 4:
            {
                cout << endl;
                return 0;
            }
            }
        }
    }
}
