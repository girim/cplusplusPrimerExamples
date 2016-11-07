/*
 * =====================================================================================
 *
 *       Filename:  email.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  Tuesday 15 August 2017 12:09:08  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */
#ifndef __MESSAGE_HPP__
#define __MESSAGE_HPP__

#include <iostream>
#include <string>
#include <set>
class Folder;

class Message
{
  public:
      //constructor
      explicit Message(const std::string &str = " "): contents_(str){}
      Message(const Message&);
      Message& operator=(const Message&);
      ~Message();

      std::string getContents();
      void saveMessage(Folder&);
      void removeMessage(Folder&);
  private:
      std::string contents_;
      std::set<Folder*> folderList_;

      void addToFolders(const Message&);
      void removeFromFolders();
};

#endif //__MESSAGE_HPP__
