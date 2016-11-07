/*
 * =====================================================================================
 *
 *       Filename:  Folder.hpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  Tuesday 15 August 2017 12:36:38  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */
#ifndef __FOLDER_HPP__
#define __FOLDER_HPP__

#include <set>
#include <string>

class Message;

class Folder
{
    public:
        Folder(const std::string &folderName = " "): folderName_(folderName) {}
        ~Folder(){}

        std::string getFolderName();
        void addMsg(Message*);
        void removeMsg(Message*);
    private:
        std::string folderName_;
        std::set<Message*> messages_;
};

#endif //__FOLDER_HPP__
