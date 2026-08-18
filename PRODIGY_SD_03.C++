#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>

struct Contact
{
    std::string name;
    std::string phone;
    std::string email;
};

class ContactManager
{
public:
    void loadContacts();
    void saveContacts();
    void addContact();
    void viewContacts();
    void editContact();
    void deleteContact();

private:
    std::vector<Contact> contacts;
    const std::string filename = "contacts.txt";

    void displayContact(const Contact &contact);
};

void ContactManager::loadContacts()
{
    std::ifstream file(filename);
    if (!file)
    {
        std::cerr << "File could not be opened!" << std::endl;
        return;
    }
    Contact contact;
    while (file >> contact.name >> contact.phone >> contact.email)
    {
        contacts.push_back(contact);
    }
    file.close();
}

void ContactManager::saveContacts()
{
    std::ofstream file(filename);
    if (!file)
    {
        std::cerr << "File could not be opened!" << std::endl;
        return;
    }
    for (const auto &contact : contacts)
    {
        file << contact.name << " " << contact.phone << " " << contact.email << std::endl;
    }
    file.close();
}

void ContactManager::addContact()
{
    Contact contact;
    std::cout << "Enter name: ";
    std::cin >> contact.name;
    std::cout << "Enter phone number: ";
    std::cin >> contact.phone;
    std::cout << "Enter email address: ";
    std::cin >> contact.email;
    contacts.push_back(contact);
    saveContacts();
}

void ContactManager::viewContacts()
{
    std::cout << std::left << std::setw(20) << "Name"
              << std::setw(20) << "Phone"
              << std::setw(30) << "Email" << std::endl;
    std::cout << std::string(70, '-') << std::endl;

    for (const auto &contact : contacts)
    {
        displayContact(contact);
    }
}

void ContactManager::editContact()
{
    std::string name;
    std::cout << "Enter the name of the contact to edit: ";
    std::cin >> name;

    for (auto &contact : contacts)
    {
        if (contact.name == name)
        {
            std::cout << "Enter new phone number: ";
            std::cin >> contact.phone;
            std::cout << "Enter new email address: ";
            std::cin >> contact.email;
            saveContacts();
            return;
        }
    }
    std::cout << "Contact not found!" << std::endl;
}

void ContactManager::deleteContact()
{
    std::string name;
    std::cout << "Enter the name of the contact to delete: ";
    std::cin >> name;

    for (auto it = contacts.begin(); it != contacts.end(); ++it)
    {
        if (it->name == name)
        {
            contacts.erase(it);
            saveContacts();
            return;
        }
    }
    std::cout << "Contact not found!" << std::endl;
}

void ContactManager::displayContact(const Contact &contact)
{
    std::cout << std::left << std::setw(20) << contact.name
              << std::setw(20) << contact.phone
              << std::setw(30) << contact.email << std::endl;
}

int main()
{
    ContactManager manager;
    manager.loadContacts();
    int choice;

    while (true)
    {
        std::cout << "Contact Manager\n";
        std::cout << "1. Add Contact\n";
        std::cout << "2. View Contacts\n";
        std::cout << "3. Edit Contact\n";
        std::cout << "4. Delete Contact\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            manager.addContact();
            break;
        case 2:
            manager.viewContacts();
            break;
        case 3:
            manager.editContact();
            break;
        case 4:
            manager.deleteContact();
            break;
        case 5:
            return 0;
        default:
            std::cout << "Invalid choice! Please try again." << std::endl;
        }
    }

    return 0;
}