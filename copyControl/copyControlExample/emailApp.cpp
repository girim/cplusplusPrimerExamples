/*
 * =====================================================================================
 *
 *       Filename:  emailApp.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  Tuesday 15 August 2017 04:41:48  IST
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
#include "Message.hpp"

int main()
{
    Folder folder_A("A");
    Folder folder_B("B");
    Folder folder_C("C");
    Folder folder_D("D");
    Message msg1("MESSAGE-1");
    Message msg2("MESSAGE-2");
    Message msg3("MESSAGE-3");

    msg1.saveMessage(folder_A);
    msg1.saveMessage(folder_B);

    msg2.saveMessage(folder_C);
    msg2.saveMessage(folder_D);

    msg3.saveMessage(folder_A);
    msg3.saveMessage(folder_B);
    msg3.saveMessage(folder_C);
    msg3.saveMessage(folder_D);

    Message msg4 = msg2;
    msg1 = msg3;

    return 0;
}


