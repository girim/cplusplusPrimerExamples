/*
 * =====================================================================================
 *
 *       Filename:  Folder.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  Tuesday 15 August 2017 04:30:49  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */
#include <iostream>
#include "Folder.hpp"

std::string Folder::getFolderName()
{
    return folderName_;
}

void Folder::addMsg(Message* msg)
{
    messages_.insert(msg);
}

void Folder::removeMsg(Message* msg)
{
    messages_.erase(msg);
}
