#include<stdio.h>
#include<stdlib.h>

void heading();
void admin();
void user();
void user_profile();
void create_profile_user();
void user_login();
void create_profile_Admin();
void admin_login();
void user_menu();
void deleteBook();
void admin_menu ( );
void help();
void showbook();
void showbook2();
void findbook();
void findbook2();
void admin_profile();
void addbook();
void editbook();
void see_all_user();
void comment_on_book();
void see_all_comment();

struct comment
{
	char userName[30];
	char nameBook[30];
	char coment[200];
};
struct comment c;

struct Login
{
	int id;
	char name[30];
	int age;
	char date[15];
	char password[30];
	int review;
	int comment;
};
struct Book_info {
	int id;
	char name[30];
	char author[30];
	int quantity;
	int rack;
};
struct Book_info a;
struct Login la;
