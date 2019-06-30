//Lab 1 cse 461 by Michael Ingersoll
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class UserPw
{
 public:
 UserPw(string user, string password); //Constructor
 string GetUser(); // returns the user
 string GetPasswd(); // returns the password
 bool Checkpw(string user, string passwd); // returns true if user and password both match

 private :
 string user, password;

};

UserPw::UserPw(string user, string password)
{
  this-> user = user;
  this-> password = password;
}

string UserPw::GetUser()
{
  return user;
}

string UserPw::GetPasswd()
{
  return password;
}

bool UserPw::Checkpw(string user, string passwd) // add this part in need to go through it more
{
  if(user == user && password == passwd)
  {
    return true;
  }
  else
  {
    return false;
  }
}

class PasswordFile
{
 public:
 PasswordFile(string filename);// opens the file and reads the names/passwords in the vector entry
 vector<UserPw> getFile(); // returns the vector entry
 void addpw(UserPw newentry); //this adds a new user/password to entry and writes entry to the file filename
 bool checkpw(string user, string passwd); // returns true is user exists and password matches

 private:
 string filename; // the file that contains password information
 vector<UserPw> entry; // the list of usernames/passwords
 void write();
};

PasswordFile::PasswordFile(string filename)
{
  this->filename = filename;  //points to this filename
  string user, password;
  ifstream pfile;
  pfile.open(this->filename.c_str());
  pfile >> user >> password;

  while (pfile.good())
  {
    entry.push_back(UserPw(user, password));
    pfile >> user >> password;
  }
} // end of PasswordFile:PasswordFile(string filename)

vector <UserPw> PasswordFile::getFile()
{
  return getFile();
}

void PasswordFile:: addpw(UserPw newentry)
{
  entry.push_back(newentry);
  write();

}

void PasswordFile::write()
{
  ofstream outfile;
  outfile.open(filename.c_str());

  for (int i = 0; i < entry.size(); i++)
  {
    outfile << entry[i].GetUser() << " " << entry[i].GetPasswd() << endl;
  }
  outfile.close();
}

bool PasswordFile::checkpw(string user, string passwd)
{
  for(int i = 0; i < entry.size(); i++)
  {
    if(entry[i].GetUser() == user && entry[i].GetPasswd() == passwd)
    {
      return true;
	cout << "User/Password match"<< endl;
    }
    else
    {
      return false;
	cout << "User/Password does not match" << endl; 
    }
  }
}

int main()
{
 PasswordFile passfile("password.txt");
// passfile.addpw(UserPw("dbotting","123qwe"));
// passfile.addpw(UserPw("egomez","qwerty"));
// passfile.addpw(UserPw("tongyu","liberty"));
 // write some lines to see if passwords match users

bool checkpw(string user, string passwd);
if (passfile.checkpw("dbotting","123qwe"))
    { cout << "dbotting works" << endl;
    }

}
