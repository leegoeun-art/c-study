#pragma once

#ifndef LIBRARY_H
#define LIBRARY_H

// 책 대여 여부를 관리하는 배열
extern int rentedBooks[10];

// 함수 선언
void printBookList(void);
void rentBook(void);
void returnBook(void);
void showRentedBooks(void);

#endif
