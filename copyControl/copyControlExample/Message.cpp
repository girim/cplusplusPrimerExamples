/*
 * =====================================================================================
 *
 *       Filename:  Message.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  Tuesday 15 August 2017 12:59:57  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */
#include <iostream>
#include "Message.hpp"
#include "Folder.hpp"

//copy constructor
Message::Message(const Message& message): contents_(message.contents_), folderList_(message.folderList_)
{
    std::cout <<"--> copy-constructor: Copying " << message.contents_ << std::endl;
    addToFolders(message);
}

//copy-assignment operator
Message& Message::operator=(const Message& rhsMsg)
{
    std::cout <<"--> copy-assignment operator: Assigning " << rhsMsg.contents_ << std::endl;
    removeFromFolders();
    contents_ = rhsMsg.contents_;
    folderList_ = rhsMsg.folderList_;
    addToFolders(rhsMsg);
    return *this;
}

//destructor
Message::~Message()
{
    std::cout <<"--> destructor: Deleting " <<  this->contents_ <<std::endl;
    removeFromFolders();
}

std::string Message::getContents()
{
    return contents_;
}

void Message::saveMessage(Folder& folder)
{
    folderList_.insert(&folder);
    folder.addMsg(this);
}

void Message::removeMessage(Folder& folder)
{
    folderList_.erase(&folder);
    folder.removeMsg(this);
}

void Message::addToFolders(const Message& msg)
{
    for(auto folder : msg.folderList_)
    {
        std::cout <<"Adding "<< this->getContents() << " to folder: " << folder->getFolderName() << std::endl;
        folder->addMsg(this);
    }
}

void Message::removeFromFolders()
{
    for(auto folder: folderList_)
    {
        std::cout << "Removing " <<this->getContents() <<" form folder: " << folder->getFolderName() << std::endl;
        folder->removeMsg(this);
    }
    folderList_.clear();
}

