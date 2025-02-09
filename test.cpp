#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fstream>

using namespace std;

class Youtube
{
public:
    string username, password, email, phoneno, confirmpassword;

public:
    void registeration()
    {
        ofstream of("users.txt", ios ::app);
        if (of.is_open())
        {
            cout << "Enter username : ";
            cin >> username;
            cout << "Enter password : ";
            cin >> password;
            if (password.length() < 8)
            {
                cout << "Password must be at least 8 characters long!" << endl;
                return;
            }
            cout << "Enter your Email address: ";
            cin >> email;
            cout << "Enter your phone no: ";
            cin >> phoneno;

            of << username << " " << password << " " << email << " " << phoneno << "\n";
            cout << "Registration successful!" << endl;
        }
        else
        {
            cout << "File opening failed!" << endl;
        }
    }

    void login()
    {
        cout << "Enter username : ";
        cin >> username;
        cout << "Enter password : ";
        cin >> password;

        if (password.length() < 8)
        {
            cout << "Password must be at least 8 characters long!" << endl;
            return;
        }

        string fileusername, filepassword, fileemail, filephoneno;
        bool userfound = false;

        ifstream ifs("users.txt");
        if (ifs.is_open())
        {

            while (ifs >> fileusername >> filepassword >> fileemail >> filephoneno)
            {
                if (fileusername == username && filepassword == password)
                {
                    userfound = true;
                    break;
                }
            }

            if (userfound)
            {
                cout << "Login successful!" << endl;
            }
            else
            {
                cout << "Invalid username or password!" << endl;
            }
        }
        else
        {
            cout << "File opening failed!" << endl;
        }

        ifs.close();
    }

    string generateOTP()
    {
        return to_string(rand() % 9000 + 1000);
    }

    void forgetpassword()
    {
        string fileusername, filephoneno, fileemail, filepassword;
        bool userfound = false;

        cout << "Are you sure you want to reset your password? (yes/no): ";
        string confirmReset;
        cin >> confirmReset;

        if (confirmReset == "yes")
        {
            cout << "Enter the username : ";
            cin >> username;

            cout << "Enter your email address : ";
            cin >> email;
            cout << "Enter your phone no : ";
            cin >> phoneno;

            ifstream ifd(username + ".txt");
            ifstream ifs("users.txt"); 
            if (ifd.is_open() && ifs.is_open())
            {
                while (ifs >> fileusername >> filepassword >> fileemail >> filephoneno)
                {
                    if (fileusername == username && fileemail == email && filephoneno == phoneno)
                    {
                        cout << "User found!" << endl;
                        userfound = true;
                        break;
                    }
                }

                if (userfound)
                {
                    string otp = generateOTP();
                    cout << "OTP sent successfully!" << endl;

                   
                    ofstream of(username + ".txt", ios::app);
                    if (of.is_open())
                    {
                        of << "otp :" << otp << endl;
                        of.close();
                    }
                    else
                    {
                        cout << "Error opening user file!" << endl;
                        return;
                    }

                    cout << "Enter the OTP sent to your email: ";
                    string enteredOTP;
                    cin >> enteredOTP;

                    if (enteredOTP == otp)
                    {
                        cout << "OTP verified successfully!" << endl;
                        cout << "Enter your new password : ";
                        cin >> password;

                        if (password.length() < 8)
                        {
                            cout << "Password must be at least 8 characters long!" << endl;
                            return;
                        }

                        cout << "Enter confirm password: ";
                        cin >> confirmpassword;

                        if (password == confirmpassword)
                        {
                            cout << "Password reset successfully!" << endl;
                        }
                        else
                        {
                            cout << "Passwords do not match. Reset failed." << endl;
                        }
                    }
                    else
                    {
                        cout << "Invalid OTP. Reset failed." << endl;
                    }
                }
                else
                {
                    cout << "User not found!" << endl;
                }

                ifs.close();
            }
            else
            {
                cout << "Unable to open users file!" << endl;
            }
        }
    }
};

class Explore
{

public:
    void trendingyt()
    {
        string srv;
        ifstream ifs("C:/Users/atish/OneDrive/Desktop/newone/cpp project/exploreyt/trendingvideos.txt");

        if (ifs.is_open())
        {
            while (getline(ifs, srv))
            {
                cout << srv << endl;
            }
            ifs.close();
        }
        else
        {
            cout << "File open not.......";
        }
    }

    void musicyt()
    {
        string srv;
        ifstream ifs("C:/Users/atish/OneDrive/Desktop/newone/cpp project/exploreyt/music.txt");

        if (ifs.is_open())
        {
            while (getline(ifs, srv))
            {
                cout << srv << endl;
            }
            ifs.close();
        }
        else
        {
            cout << "File open not.......";
        }
    }

    void filmsyt()
    {
        string srv;
        ifstream ifs("C:/Users/atish/OneDrive/Desktop/newone/cpp project/exploreyt/films.txt");

        if (ifs.is_open())
        {
            while (getline(ifs, srv))
            {
                cout << srv << endl;
            }
            ifs.close();
        }
        else
        {
            cout << "File open not.......";
        }
    }

    void gamingyt()
    {
        string srv;
        ifstream ifs("C:/Users/atish/OneDrive/Desktop/newone/cpp project/exploreyt/gaming.txt");

        if (ifs.is_open())
        {
            while (getline(ifs, srv))
            {
                cout << srv << endl;
            }
            ifs.close();
        }
        else
        {
            cout << "File open not.......";
        }
    }

    void sportyt()
    {
        string srv;
        ifstream ifs("C:/Users/atish/OneDrive/Desktop/newone/cpp project/exploreyt/sport.txt");

        if (ifs.is_open())
        {
            while (getline(ifs, srv))
            {
                cout << srv << endl;
            }
            ifs.close();
        }
        else
        {
            cout << "File open not.......";
        }
    }

    void podcastgyt()
    {
        string srv;
        ifstream ifs("C:/Users/atish/OneDrive/Desktop/newone/cpp project/exploreyt/podcast.txt");

        if (ifs.is_open())
        {
            while (getline(ifs, srv))
            {
                cout << srv << endl;
            }
            ifs.close();
        }
        else
        {
            cout << "File open not.......";
        }
    }

    void courseyt()
    {
        string srv;
        ifstream ifs("C:/Users/atish/OneDrive/Desktop/newone/cpp project/exploreyt/courses.txt");

        if (ifs.is_open())
        {
            while (getline(ifs, srv))
            {
                cout << srv << endl;
            }
            ifs.close();
        }
        else
        {
            cout << "File open not.......";
        }
    }

    void ytshorts()
    {
        string srv;
        ifstream ifs("C:/Users/atish/OneDrive/Desktop/newone/cpp project/exploreyt/ytshorts.txt");

        if (ifs.is_open())
        {
            while (getline(ifs, srv))
            {
                cout << srv << endl;
            }
            ifs.close();
        }
        else
        {
            cout << "File open not.......";
        }
    }
};

class subscription
{
public:
    void subscribeyt()
    {
        string channels[] = {
            "Tech with Tim",
            "Programming Hub",
            "CrashCourse",
            "SmarterEveryDay",
            "Binging with Babish"};

        int channelCount = sizeof(channels) / sizeof(channels[0]);
        string channelName;
        bool found = false;

        cout << "Available channels:" << endl;
        for (int i = 0; i < channelCount; i++)
        {
            cout << "- " << channels[i] << endl;
        }

        cout << "\nEnter the channel name you want to subscribe to: ";
        cin.ignore();
        getline(cin, channelName);

        for (int i = 0; i < channelCount; i++)
        {
            if (channels[i] == channelName)
            {
                found = true;
                break;
            }
        }

        if (found)
        {
            ofstream subscriptionFile("subscribe.txt", ios::app);
            if (subscriptionFile.is_open())
            {
                subscriptionFile << channelName << endl;
                cout << "Successfully subscribed to: " << channelName << endl;
                subscriptionFile.close();
            }
            else
            {
                cout << "Error: Unable to open the 'subscription.txt' file for writing!" << endl;
            }
        }
        else
        {
            cout << "Error: Channel not found in the list!" << endl;
        }
    }

    void viewSubscriptions()
    {
        ifstream subscriptionFile("subscribe.txt");
        string line;
        cout << "\nYour subscriptions:" << endl;
        if (subscriptionFile.is_open())
        {
            while (getline(subscriptionFile, line))
            {
                cout << "- " << line << endl;
            }
            subscriptionFile.close();
        }
        else
        {
            cout << "Error: Unable to open the 'subscription.txt' file for reading!" << endl;
        }
    }

    void unsubscribeYT()
    {
        ifstream subscriptionFile("subscribe.txt");
        ofstream tempFile("unsubcrb.txt");
        string line, channelNameToUnsubscribe;
        bool found = false;

        cout << "\nEnter the channel name you want to unsubscribe from: ";
        cin.ignore();
        getline(cin, channelNameToUnsubscribe);

        if (subscriptionFile.is_open())
        {
            while (getline(subscriptionFile, line))
            {
                if (line != channelNameToUnsubscribe)
                {
                    tempFile << line << endl;
                }
                else
                {
                    found = true;
                }
            }
            subscriptionFile.close();
            tempFile.close();

            if (found)
            {
                remove("subscribe.txt");
                rename("temp.txt", "subscribe.txt");
                cout << "Successfully unsubscribed from: " << channelNameToUnsubscribe << endl;
            }
            else
            {
                cout << "Error: Channel not found in your subscriptions!" << endl;
            }
        }
        else
        {
            cout << "Error: Unable to open the 'subscribe.txt' file for reading!" << endl;
        }
    }
};

int main()
{
    Youtube y;
    int choice;

    do
    {
        cout << "1. REGISTER\n";
        cout << "2. LOGIN\n";
        cout << "3. Forgot Password\n";
        cout << "4. Explore videos\n";
        cout << "5. Subscriptions\n";
        cout << "0. Exit\n"; // Exit option

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            y.registeration();
            break;
        case 2:
            y.login();
            break;
        case 3:
            y.forgetpassword();
            break;
        case 4:
        {
            Explore e;
            char videoChoice;
            do
            {
                cout << "Do you want to watch:\n";
                cout << "----> a. Long videos\n";
                cout << "----> b. Shorts\n";
                cout << "----> x. Back to main menu\n";
                cout << "Enter your choice: ";
                cin >> videoChoice;

                switch (videoChoice)
                {
                case 'a': // Long videos
                    cout << "---->   a: Trending " << endl;
                    cout << "---->   b: Music  " << endl;
                    cout << "---->   c: Films " << endl;
                    cout << "---->   d: Gaming " << endl;
                    cout << "---->   e: sport " << endl;
                    cout << "---->   f: Podcast " << endl;
                    cout << "---->   g: Course " << endl;

                    char choice1;
                    cout << "Enter your choice: ";
                    cin >> choice1;

                    switch (choice1)
                    {
                    case 'a':
                        e.trendingyt();
                        break;
                    case 'b':
                        e.musicyt();
                        break;
                    case 'c':
                        e.filmsyt();
                        break;
                    case 'd':
                        e.gamingyt();
                        break;
                    case 'e':
                        e.sportyt();
                        break;
                    case 'f':
                        e.podcastgyt();
                        break;
                    case 'g':
                        e.courseyt();
                        break;
                    default:
                        cout << "Not found..\n";
                        break;
                    }
                    break;

                case 'b': // Shorts
                    e.ytshorts();
                    break;

                case 'x': // Back to main menu
                    cout << "Returning to main menu...\n";
                    break;

                default:
                    cout << "Invalid choice. Please try again.\n";
                    break;
                }
            } while (videoChoice != 'x'); 
            break;
        }

        case 5:
        {
            subscription s;
            char choice2;
            do
            {
                cout << "-----> a. Subscribe to channels " << endl;
                cout << "-----> b. View subscriptions " << endl;
                cout << "-----> c. Unsubscribe to channels " << endl;
                cout << "-----> x. Back to main menu\n";
                cout << "Enter your choice : ";
                cin >> choice2;

                switch (choice2)
                {
                case 'a':
                    s.subscribeyt();
                    break;
                case 'b':
                    s.viewSubscriptions();
                    break;
                case 'c':
                    s.unsubscribeYT();
                    break;
                case 'x': // Back to main menu
                    cout << "Returning to main menu...\n";
                    break;
                default:
                    cout << "Invalid choice!\n";
                    break;
                }
            } while (choice2 != 'x');
            break;
        }

        case 0: 
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
            break;
        }
    } while (choice != 0);
}
