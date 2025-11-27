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
void showbook();
void showbook2();
void findbook();
void findbook2();
void admin_profile();
void addbook();
void editbook();
void see_all_user();

struct Login{
	int id;
	char name[30];
	char date[15];
	char password[30];        };

struct Book_info {
	int id;
	char name[30];
	char author[30];
	int quantity;              };
	
struct Book_info a;
struct Login la;

FILE *loginF, *loginF2, *file, *file2;
int pwd_ceck = 0, t = 0;
int main(){
	heading();          }

void heading() {
	system ( "cls" );
	int d;
	printf ( "\n\n\n\t\t\t   Library System \n" );
	printf ( "\n\n\t\t   1. Admin" );
	printf ( "\n\t\t   2. User " );
	printf ( "\n\n\t\t   Enter you choice: " );
	scanf ( "%d", &d );
	if ( d == 1 ){
		admin();	}
	else if ( d == 2 ) {
			user();		}
		else {
			printf ( "\n\n\t\t \a  wrong choice!" );
			fflush ( stdin );
			getchar();
			heading();		}}

void admin(){                       // admin part Bellow....
	system ( "cls" );
	int d;
	printf ( "\n\n\t\t ========> Admin <========" );
	printf ( "\n\n\t\t 1. New" );
	printf ( "\n\t\t 2. Login" );
	printf ( "\n\t\t 0. Back" );
	printf ( "\n\n\t\t   Enter you choice: " );
	scanf ( "%d", &d );
	if ( d == 0 ) { heading();}
	else if ( d == 1 ) {
			create_profile_Admin();		}
	else if ( d == 2 ) {
			admin_login();			}
	else {
			printf ( "wrong choice!" );
			fflush ( stdin );
			getchar();
			admin();				}}

void create_profile_Admin() {
	system ( "cls" );
	loginF2 = fopen ( "long2.txt", "a" );
	printf ( "\n\n\t\t ****** Create A Admin Profile *******" );
	printf ( "\n\n\t\t  Enter ID: " );
	scanf ( "%d", &la.id );
	fflush ( stdin );
	printf ( "\n\t\t  Enter Name: " );
	gets ( la.name );
	fflush ( stdin );
	printf ( "\n\t\t  Enter Date: " );
	fflush ( stdin );
	gets ( la.date );
	fflush ( stdin );
	printf ( "\n\t\t  Enter password: " );
	scanf ( "%s", la.password );
	fwrite ( &la, sizeof ( la ), 1, loginF2 );
	printf ( "\n\n\t\t Profile Create Successfully!" );
	fclose ( loginF2 );
	fflush ( stdin );
	getchar();
	admin(); }
int check2 = 1;

void admin_login() {
	system ( "cls" );
	int d, c = 0;
	char pwd[30];
	printf ( "\n\n\t\t  ***** Login page for Admin ****" );
	printf ( "\n\n\t\t  Enter ID: " );
	scanf ( "%d", &d );
	printf ( "\n\t\t  Enter password: " );
	fflush ( stdin );
	gets ( pwd );
	loginF2 = fopen ( "long2.txt", "rb+" );
	while ( fread ( &la, sizeof ( la ), 1, loginF2 ) == 1 ) {
		if ( la.id == d && strcmp ( la.password,  pwd ) == 0 ) {
			pwd_ceck = la.id;
			c = 1;		}	}
	fclose ( loginF2 );
	if ( c == 1 ) {
		admin_menu ();}
	else {
		printf ( "\n\n\t\t wrong ! ID or password %d to 3", check2 );
		fflush ( stdin );
		getchar();
		if ( check2 == 3 ) { exit ( 0 ); }
		check2++;
		admin_login();
	}}

void admin_menu ( ) {
	t = 1;
	system ( "cls" );
	char *nam;
	int d;
	loginF2 = fopen ( "long2.txt", "rb+" );
	while ( fread ( &la, sizeof ( la ), 1, loginF2 ) == 1 ) {
		if ( la.id == pwd_ceck ) {
			nam = la.name;		}	}
	printf ( "\n\n\t\t====>> Welcome %s in Admin Menu <<===", nam );
	printf ( "\n\n\t\t 1. Profile" );
	printf ( "\n\t\t 2. see All user" );
	printf ( "\n\t\t 3. add book" );
	printf ( "\n\t\t 4. show books" );
	printf ( "\n\t\t 5. Find book" );
	printf ( "\n\t\t 6. edit book" );
	printf ( "\n\t\t 7. Delete book" );
	printf ( "\n\t\t 8. logout" );
	printf ( "\n\t\t 0. Back" );
	printf ( "\n\n\t\t Enter you choice: " );
	fflush ( stdin );
	scanf ( "%d", &d );
	if ( d == 0 ) {heading();}
	else if ( d == 1 ) {
			admin_profile();}
		else if ( d == 2 ) {
				see_all_user();			}
				else if ( d == 3 ) {
						addbook();		}
					else if ( d == 4 ) {
							showbook();  }
						else if ( d == 5 ) {
								findbook();	}
							else if ( d == 6 ) {
									editbook();		}
								else if ( d == 7 ) {
										deleteBook();		}
									else if ( d == 8 ) {
											int i;
											system ( "cls" );
											printf ( " \n\t\t closing program" );
											for ( i = 1; i < 1e9; i++ ) {}
											exit ( 0 );			}}
void admin_profile() {
	system ( "cls" );
	printf ( "\n\n\t\t     Admin Profile\n" );
	loginF2 = fopen ( "long2.txt", "rb+" );
	while ( fread ( &la, sizeof ( la ), 1, loginF2 ) == 1 ) {
		if ( pwd_ceck == la.id ) {
			printf ( "\n\n\t\tName: %s", la.name );
			printf ( "\n\t\tPassword: %s", la.password );
		}}
	printf ( "\n\n\t\t press any key.... " );
	fflush ( stdin );
	getchar();
	admin_menu();
}

void see_all_user() {
	int i = 1;
	system ( "cls" );
	printf ( "\n\n\t\t     All User Profile\n" );
	loginF = fopen ( "long.txt", "rb+" );
	while ( fread ( &la, sizeof ( la ), 1, loginF ) == 1 ) {
		printf ( "\n\n\t\t   Serial: %d\n", i++ );
		printf ( "\n\t\tName: %s", la.name );
		printf ( "\n\t\tDate: %s", la.date );
		printf ( "\n\t\tPassword: %s", la.password );	}
	printf ( "\n\n\t\t press any key.... " );
	fflush ( stdin );
	getchar();
	admin_menu();       }

void addbook(){
	system ( "cls" );
	int d, count = 0;
	printf ( "\n\n \t\t ****************** Add Book ***************\n\n" );
	file = fopen ( "books.dat", "ab+" );
	printf ( "\t\t Enter ID: " );
	fflush ( stdin );
	scanf ( "%d", &d );
	rewind ( file );
	while ( fread ( &a, sizeof ( a ), 1, file ) == 1 ) {
		if ( d == a.id ) {
			printf ( "\n\n\t\t This book is Already in Lbirary...." );
			count = 1;
		}}
	if ( count == 1 ) {
		fflush ( stdin );
		getchar();
		admin_menu();
	}
	a.id = d;
	printf ( "\n\t\t Enter Name: " );
	fflush ( stdin );
	scanf ( "%s", a.name );
	printf ( "\t\t Enter Author: " );
	fflush ( stdin );
	scanf ( "%s", a.author );
	printf ( "\t\t Enter quantity: " );
	fflush ( stdin );
	scanf ( "%d", &a.quantity );
	fseek ( file, 0, SEEK_END );
	fwrite ( &a, sizeof ( a ), 1, file );
	fclose ( file );
	printf ( "\n\n\t\t Add book sucessfully!" );
	fflush ( stdin );
	getchar();
	admin_menu();
}
void deleteBook() {
	system ( "cls" );
	int d, count = 0;
	printf ( "\n\n\t\t *************** delete Book **************" );
	printf ( "\n\n\t\t Enter ID for delete Book" );
	scanf ( "%d", &d );
	file = fopen ( "books.dat", "rb+" );
	rewind ( file );
	while ( fread ( &a, sizeof ( a ), 1, file ) == 1 ) {
		if ( d == a.id ) {
			printf ( "\n\t\t Book is Availble!\n" );
			printf ( "\n\t\t Book Name is: %s", a.name );
			count = 1;		}	}
	if ( count == 0 ) {
		printf ( "\n\t\t Book is not Availble" );
	}
	else {
		file2 = fopen ( "text.dat", "wb+" );
		rewind ( file );
		while ( fread ( &a, sizeof ( a ), 1, file ) == 1 ) {
			if ( d != a.id ) {

				fseek ( file2, 0, SEEK_CUR );
				fwrite ( &a, sizeof ( a ), 1, file2 );
			}
		}
		fclose ( file );
		fclose ( file2 );
		remove ( "books.dat" );
		rename ( "text.dat", "books.dat" );
		file = fopen ( "books.dat", "rb" );
		fclose ( file );
		printf ( "\n\n\t\t Delete book is sucessfully!\n" );

	}
	printf ( "\n\n\t\t press any key" );
	fflush ( stdin );
	getchar();
	admin_menu();        }
void editbook() {
	system ( "cls" );
	int d, count = 0;
	printf ( "\n\n\t\t ************* Edit book *************\n\n" );
	file = fopen ( "books.dat", "rb+" );
	printf ( "\n\t\t Enter ID: " );
	scanf ( "%d", &d );

	while ( fread ( &a, sizeof ( a ), 1, file ) == 1 ) {

		if ( d == a.id ) {

			printf ( "\n\t\t Book is Availble!\n" );
			printf ( "\n\n \t\t ID: %d", a.id );
			printf ( "\n\t\t Enter New Name: " );
			scanf ( "%s", a.name );
			printf ( "\n\t\t Enter New Author: " );
			scanf ( "%s", a.author );
			printf ( "\n\t\t Enter New quantity: " );
			scanf ( "%d", &a.quantity );
			printf ( "\n\t\t Enter New Rack: " );
			fseek ( file, ftell ( file ) - sizeof ( a ), 0 );
			fwrite ( &a, sizeof ( a ), 1, file );
			fclose ( file );
			count = 1;
		}
	}
	if ( count == 0 ) {
		printf ( "\n\n\t\t Book is Not Found!" );
	}
	printf ( "\n\n\t\t press any key...." );
	fflush ( stdin );
	getchar();
	admin_menu();        }
