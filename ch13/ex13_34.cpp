#include <iostream>
#include <string>
#include <set>

class Message;


class Folder {
public:
    Folder() {
        static int folderId;
        id = folderId++;
    };

    void addMessage(Message *message);

    void removeMessage(Message *message);

    size_t size();

    void print();

    ~Folder();

private:
    int id;
    std::set<Message *> messages;
};

class Message {
    friend class Folder;

public:
    explicit Message(const std::string &str = "") : contents(str) { }

    Message(const Message &);

    Message &operator=(const Message &);

    ~Message();

    // Folder add/remove
    void save(Folder &);

    void remove(Folder &);

    void print();

private:

    std::string contents;

    std::set<Folder *> folders;

    void add_to_folders(const Message &);

    void remove_from_folders();
};



void Folder::addMessage(Message *message) {
    messages.insert(message);
}

void Folder::removeMessage(Message *message) {
    messages.erase(message);
}

size_t Folder:: size() {
    return messages.size();
}

void Folder::print() {
    std::cout << "folders(" << id << "): " << size() << std::endl;
}

Folder::~Folder() {
    std::cout << "~Folder: ";
    print();

    for (auto message:messages) {
        message->remove(*this);
    }
}

Message::Message(const Message &message) : contents(message.contents), folders(message.folders) {
    add_to_folders(message);
}

Message &Message::operator=(const Message &message) {
    remove_from_folders();
    contents = message.contents;
    folders = message.folders;
    add_to_folders(message);
    return *this;
}

Message::~Message() {
    std::cout << "~Message: ";
    print();
    remove_from_folders();
}

void Message::save(Folder &folder) {
    folders.insert(&folder);
    folder.addMessage(this);
}

void Message::remove(Folder &folder) {
    folders.erase(&folder);
    folder.removeMessage(this);
}

void Message::add_to_folders(const Message &message) {
    for (auto folder:message.folders) {
        folder->addMessage(this);
    }
}

void Message::remove_from_folders() {
    for (auto folder:folders) {
        folder->removeMessage(this);
    }
}

void Message::print() {
    std::cout << "folders: " << folders.size() << " content:" << contents << std::endl;
}


int main() {
    Folder folder1;
    Message m1("aa");
    m1.save(folder1);
    m1.remove(folder1);
    Message m2 = m1;

    m1.print();
    m2.print();


    Folder folder2;
    {
        Message m3 = m1;
        m3.save(folder1);
        m3.remove(folder1);
        folder1.print();
        m3.print();
        m3.save(folder2);
        m3.print();
        folder1.print();
        folder2.print();
    }

    m2.save(folder2);
    m2.print();
    m2.remove(folder1);
    std::cout << "folders1:" << folder1.size() << "     folders2:" << folder2.size() << std::endl;

    Message m4("bb");
    m4.save(folder2);
    m4.print();
    std::cout << "folders1:" << folder1.size() << "     folders2:" << folder2.size() << std::endl;
    m4 = m2;
    m4.print();
    std::cout << "folders1:" << folder1.size() << "     folders2:" << folder2.size() << std::endl;

    return 0;
}
