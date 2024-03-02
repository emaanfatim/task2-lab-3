#include <iostream>
#include <map>
#include <string>
using namespace std;

class Details {
private:
    string email;
    string phoneNumber;
    string homeAddress;

public:
    Details() : email(""), phoneNumber(""), homeAddress("") {}

    Details(string email, string phoneNumber, string homeAddress)
        : email(email), phoneNumber(phoneNumber), homeAddress(homeAddress) {}

    string getEmail() const {
        return email;
    }

    string getPhoneNumber() const {
        return phoneNumber;
    }

    string getHomeAddress() const {
        return homeAddress;
    }
};

int main() {
    map<int, string> contactNames = {
        {1, "Emaan"},
        {2, "Arslan"},
        {3, "Moiz"},
        {4, "Ayesha"},
        {5, "Madeiha"}
    };

    cout << "Contacts:" << endl;
    for (const auto& pair : contactNames) {
        cout << pair.first << " : " << pair.second << endl;
    }

    int choice;
    cout << "Enter the corresponding number to find the details or press 0 to add a new contact manager: ";
    cin >> choice;
    cin.ignore();
    if (choice == 0) {
        string name, email, phoneNumber, homeAddress;
        cout << "Enter name of the contact manager: ";
        getline(cin, name);


        auto it = contactNames.begin();
        while (it != contactNames.end()) {
            if (it->second == name) {
                cout << "Contact manager with this name already exists!" << endl;
                return 0;
            }
            ++it;
        }

        cout << "Enter email: ";
        getline(cin, email);
        cout << "Enter phone number: ";
        getline(cin, phoneNumber);
        cout << "Enter home address: ";
        getline(cin, homeAddress);


        contactNames[contactNames.size() + 1] = name;


        Details details(email, phoneNumber, homeAddress);
        map<string, Details> contactDetails;
        contactDetails[name] = details;
    }
    else {

        map<string, Details> contactDetails;
        contactDetails["Emaan"] = Details("emaan.mursleen@gmail.com", "03011076229", "51 Street, City Islamabad");
        contactDetails["Arslan"] = Details("Arslan@gmail.com", "03040517871", "82 Street,832-F house#, Lahore");
        contactDetails["Moiz"] = Details("moiz@gmail.com", "0307548432", "789 Road, Karachi");
        contactDetails["Ayesha"] = Details("ayesha@gmail.com", "03013429689", "101 DHA, Multan");
        contactDetails["Madeiha"] = Details("madeihaa@gmail.com", "0304502845", "22 Lane, Pindi");

        auto it = contactDetails.find(contactNames[choice]);
        if (it != contactDetails.end()) {
            cout << "Name: " << contactNames[choice] << endl;
            cout << "Email: " << it->second.getEmail() << endl;
            cout << "Phone Number: " << it->second.getPhoneNumber() << endl;
            cout << "Home Address: " << it->second.getHomeAddress() << endl;
        }
        else {
            cout << "Contact not found!! Enter the correct number." << endl;
        }
    }

    return 0;
}
