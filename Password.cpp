// Lab 1 CSE 461 by Michael Ingersoll
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class UserPw
{
 public:
  UserPw(std::string user, std::string password);      // Constructor
  std::string GetUser() const;                          // returns the user
  std::string GetPasswd() const;                        // returns the password
  bool Checkpw(std::string user, std::string passwd) const; // true if user and password both match

 private:
  std::string user, password;
};

UserPw::UserPw(std::string user, std::string password)
{
  this->user = user;
  this->password = password;
}

std::string UserPw::GetUser() const
{
  return user;
}

std::string UserPw::GetPasswd() const
{
  return password;
}

bool UserPw::Checkpw(std::string user, std::string passwd) const
{
  // this-> is needed because the parameter "user" hides the member "user"
  return this->user == user && this->password == passwd;
}

class PasswordFile
{
 public:
  PasswordFile(std::string filename);        // opens the file and reads the names/passwords into the vector
  std::vector<UserPw> getFile() const;       // returns the vector of entries
  void addpw(UserPw newentry);               // adds a new user/password and writes entries to the file
  bool checkpw(std::string user, std::string passwd) const; // true if user exists and password matches

 private:
  std::string filename;                      // the file that contains password information
  std::vector<UserPw> entry;                 // the list of usernames/passwords
  void write() const;
};

PasswordFile::PasswordFile(std::string filename)
{
  this->filename = filename;
  std::string user, password;
  std::ifstream pfile(this->filename.c_str());

  while (pfile >> user >> password)
  {
    entry.push_back(UserPw(user, password));
  }
}

std::vector<UserPw> PasswordFile::getFile() const
{
  return entry;
}

void PasswordFile::addpw(UserPw newentry)
{
  entry.push_back(newentry);
  write();
}

void PasswordFile::write() const
{
  std::ofstream outfile(filename.c_str());

  for (size_t i = 0; i < entry.size(); i++)
  {
    outfile << entry[i].GetUser() << " " << entry[i].GetPasswd() << std::endl;
  }
}

bool PasswordFile::checkpw(std::string user, std::string passwd) const
{
  // check every entry; only give up after the whole list has been searched
  for (size_t i = 0; i < entry.size(); i++)
  {
    if (entry[i].Checkpw(user, passwd))
    {
      return true;
    }
  }
  return false;
}

int main()
{
  PasswordFile passfile("password.txt");

  // Uncomment on the first run to create password.txt, then comment out again
  // passfile.addpw(UserPw("dbotting", "123qwe"));
  // passfile.addpw(UserPw("egomez", "qwerty"));
  // passfile.addpw(UserPw("tongyu", "liberty"));

  // write some lines to see if passwords match users
  if (passfile.checkpw("dbotting", "123qwe"))
  {
    std::cout << "dbotting works" << std::endl;
  }
  else
  {
    std::cout << "dbotting does not match" << std::endl;
  }

  if (passfile.checkpw("tongyu", "liberty"))
  {
    std::cout << "tongyu works (not the first entry)" << std::endl;
  }

  if (!passfile.checkpw("dbotting", "wrongpass"))
  {
    std::cout << "wrong password correctly rejected" << std::endl;
  }

  return 0;
}
