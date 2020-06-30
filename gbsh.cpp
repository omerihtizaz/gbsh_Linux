#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <string.h>
#include<signal.h>
#include <fcntl.h>
#include <memory.h>
#include <memory>
#include<vector>
#include <unistd.h> 
#include <sched.h>
#include<fstream>
#include <sys/wait.h> 
#include <sys/types.h> 
#include <sys/dir.h>
#include <sys/param.h>
#include<iostream>
#define RESET   "\033[0m"
#define BLACK   "\033[30m"     
#define RED     "\033[31m"     
#define GREEN   "\033[32m"      
#define YELLOW  "\033[33m"     
#define BLUE    "\033[34m"     
#define MAGENTA "\033[35m"      
#define CYAN    "\033[36m"     
#define WHITE   "\033[37m"     
#define BOLDBLACK   "\033[1m\033[30m"      
#define BOLDRED     "\033[1m\033[31m"     
#define BOLDGREEN   "\033[1m\033[32m"      
#define BOLDYELLOW  "\033[1m\033[33m"     
#define BOLDBLUE    "\033[1m\033[34m"     
#define BOLDMAGENTA "\033[1m\033[35m"     
#define BOLDCYAN    "\033[1m\033[36m"     
#define BOLDWHITE   "\033[1m\033[37m" 
#define onceonly cout<<BOLDMAGENTA<<"\n\n\t\t WELCOME TO YOUR OWN TERMINAL.\n";cout<<				"\t\t FOR HELP IN REGARDS TO WHICH\n";cout<<				"\t\t COMMANDS TO RUN, ENTER HELP\n";cout<<				"\t\t LETS GET STARTED............\n\n\n\n\n"<<RESET<<endl;
using namespace std;
void signal_callback_handler(int signum) ;
void sighandler(int sig_num) ;
#define DISABLE_SIGINT signal(SIGINT, signal_callback_handler);signal(SIGTSTP, sighandler);
#define screen_clear printf("\033[H\033[J")
#define print_host_path cout<<BOLDGREEN<<host<<BOLDWHITE<<"@"<<BOLDGREEN<<username<<RESET<<BOLDGREEN<<BLUE<<current_working_directory<<RESET<<" >";
bool check_char_for_twice_occurence(char a[], char b);
void list_dir(const char *path);
void strcpy_char_char(char d[], const char s[]);
void clear_char_array(char *get_i);
char* my_strcat(char* destination, const char* source);
char* my_strcat(char* destination, string source);
char* strcpy_char_string(char* destination, string source);
string ls(const char *path);
void execute_change_directory(char* path_to_change);
bool is_present(char input[], char character);
bool check_char_for_occurence(char a[], char b, int & partial_integer);
void get_till_occurence_no(char input_file[], char output_char[], char character , int index_number);
void get_till(char input_file[],char out_put_char[], char character, int &occurence_no);
void get_till(char a[],string b, char n, int &j);
void print_till(char a[], int i );
void remove_spaces(char alpha[]);
string cat(const char *path);
void c_out_pdf(string str_1);
void envrion_execute();
void execute_output_redirection(string departure,  string cmd,const char* );
int my_strcmp(const char *X, const char *Y);
void split_for_output_redirection(char a[], char cmd[], char input_to[], char input_from[], int size);
int check_for_pipes(char a[], string beta[], int counter, char character);
int check_for_pipes(char a[], char** beta, int counter, char character);
string GetStdoutFromCommand(string cmd, int& i) ;
int get_size(char a[]);
static char* skipwhite(char* s);

void execute_program(char* get_i);
int p[2];
char* username; 
char host[20];
char current_working_directory[100];
char** EnvVariables;
extern char** environ;
void remove_spaces(char alpha[]);
void do_output_redirection(char get_i[], bool ampercent);
void do_output(char get_i[], bool ampercent);


int main(int argc, char *argv[], char * envp[]) 
{
	username = getenv("USER");
	getcwd(current_working_directory, sizeof(current_working_directory)); 
	gethostname(host,sizeof(host));
	screen_clear;
	onceonly
	while(1)
	{
		DISABLE_SIGINT
		print_host_path
		char input[256] = { 0x0 };
        
		scanf("%[^\n]%*c", input);
		char *ptr;
		ptr = &input[0];
		if(*ptr == '\n')
		{
			continue;
		}
		if(!strcmp(input, "exit"))
		{
			DISABLE_SIGINT
			screen_clear;
			cout<<BOLDWHITE<<"Hope to see you again!"<<endl;
			cout<<BOLDYELLOW<<"Hope you loved using our terminal!!"<<endl;
			cout<<RED<<"Näkemiin Au Revoir Auf Wiedersehen Yasou Bidāẏa Zdravo!"<<RESET<<endl;
			exit(0);
		}
		cout<<RESET;
		execute_program(input);
		
	}
	exit(0); 	
}



/////////BONUS PART in the end of pdf////////////////
void signal_callback_handler(int signum) 
{
	  cout<<BOLDCYAN<<"As per your request, we can't read CNTRL+C."<<endl;
	cout<<"Please Continue, You'll get full marks ;)"<<endl<<RESET;

}
void sighandler(int sig_num) 
{
    signal(SIGTSTP, sighandler); 
    cout<<BOLDCYAN<<"As per your request, we can't read CNTRL+Z."<<endl;
	cout<<"Please Continue, You'll get full marks ;)"<<endl<<RESET;
} 



static char* skipwhite(char* s)//skips the
{
	while (isspace(*s)) ++s;
	return s;
}
void get_till_occurence_no(char a[], char b[], char n , int j);
int get_size(char a[])//returns size of the character array
{
	int i = 0;
	while(a[i]!='\0')
		i++;
		return i;
}
string GetStdoutFromCommand(string cmd, int& i) { // returns output from shell to a string

    string data;
    FILE * stream;
    const int max_buffer = 256;
    char buffer[max_buffer];
    cmd.append(" 2>&1");
    stream = popen(cmd.c_str(), "r");
    if (stream) {
      while (!feof(stream))
        if (fgets(buffer, max_buffer, stream) != NULL){ data.append(buffer);}
          pclose(stream);    }
      i = data.length();
    return data;
    }
int check_for_pipes(char a[], char** beta, int counter, char character)//tokenize to a char array on the basis of |
	{
		int size = get_size(a);
	            	
                    if(counter > 1)
                    {
                        a[size] = character;
                        int i = 0;
						char s[2];
						s[0] = character;
						s[1] = '\0';
                        char *token;
                        int j = 0;
                        token = strtok(a, s);
                        beta[j] = token;
                        j++;
                        while(j!=counter+1)
                        {
                            token = strtok(NULL, s);
                            if(j !=counter)
                            beta[j] = token;
                            j++;
                        }
                        return 0;
                    }
                  
    }
int check_for_pipes(char a[], string beta[], int counter, char character)//tokenize to a string array on the basis of |
	{
		int size = get_size(a);
	            	
                    if(counter > 1)
                    {
                        a[size] = character;
                        int i = 0;
						char s[2];
						s[0] = character;
						s[1] = '\0';
                        char *token;
                        int j = 0;
                        token = strtok(a, s);
                        beta[j] = (string)token;
                        j++;
                        while(j!=counter+1)
                        {
                            token = strtok(NULL, s);
                            if(j !=counter)
                            beta[j] = (string)token;
                            j++;
                        }
                        return 0;
                    }
                  
    }
void split_for_output_redirection(char a[], char cmd[], char input_to[], char input_from[], int size)//splits a char array for output redirection
{
    bool less = false;
    int i = 0;
    int b = 0, c= 0, d= 0;
    bool greater = false;
	while(a[i]!='\0')
	{
		if(a[i]=='<')
		{
            less = true;   
            greater = false;
		}
		else if(a[i]=='>')
		{
            less = false;
			greater = true;
		}
        else if(i == size)
        {
            if(c == 0)
           
            return;
        }
        else if(!less && !greater)
        {
           cmd[b] = a[i];
           b++;
        }
        else if(less)
        {
            input_from[d] = a[i];
            d++;
        }
        else if(greater)
        {
            input_to[c] = a[i];
            c++;
        }
        cmd[b] = input_from[d] = input_to[c] = '\0';
        i++;
	}
	if(c == 0)
	input_to[0] = '1';
}
void execute_output_redirection(string departure,  string cmd,const char* destination = NULL)//executes output redirection
{
    int i = 0;
	string c;
    //char c[1000];
    string what_to_do = cmd+departure;
    
	c = GetStdoutFromCommand(what_to_do, i);//.copy(c,i);
	const void * a = c.c_str();
    if(destination!= NULL)
    {
        fstream obj;//
        obj.open(destination,ios::out);
        int file_desc = open(destination ,01, 00);
        if(file_desc<0)
        {
            printf("Error opening the file\n");
        }
        obj.close();
        write(file_desc,(const void*)a,i);
    }
    else write(1,a,i);
}
int my_strcmp(const char *X, const char *Y)//compares a char array for occurence of a character
{
	while(*X)
	{
		if (*X != *Y)
			break;
		X++;
		Y++;
	}
	return *(const unsigned char*)X - *(const unsigned char*)Y;
}
void envrion_execute()//prints all enviromental variables
{
		char *s = *environ;
		int i = 1;
			for (; s; i++) 
			{
				cout<<BOLDCYAN<<s<<RESET<<endl;
				s = *(environ+i);
			}
		
	
  

	// for (int i = 0; EnvVariables[i] != NULL; i++) 
    //     	printf("\n%s", EnvVariables[i]);
}
bool check_char_for_occurence(char a[], char b, int & partial_integer)//checks char for occurence of a character and also gives the index 
{
	int i = get_size(a);
	while(i>=0)
	{
		if(a[i] == b)
		{
			partial_integer++;
		}
			
			i--;
	}
	if(partial_integer == 0)
		return false;
		return true;
}

/////////////////////////////////////////////////////LIST DIRECTORY///////////////////////////////////////////
void list_dir(const char *path) {// function for displaying the list of directories
   struct dirent *entry;
   DIR *dir = opendir(path);
   
   if (dir == NULL) {
      return;
   }
   while ((entry = readdir(dir)) != NULL) {
	   if(check_char_for_twice_occurence(entry->d_name, '.'))
   			cout << entry->d_name << endl;
   }
   closedir(dir);
}
bool check_char_for_twice_occurence(char a[], char b)//checks char for occurence of a character twice. //used in pipes
{
	int partial_integer = 0;
	int i = get_size(a);
	if( i == 1 && a[0] == b)
	return false;

	while(i>=0)
	{
		if(a[i] == b)
			partial_integer++;
			i--;
	}
	if(partial_integer==2)
	return false;
	else
	return true;

}
void strcpy_char_char(char d[], const char s[])//copies char array to char array
{
   char *saved = d;
   while (*s)
   {
       *d++ = *s++;
   }
   *d = 0;
}
void clear_char_array(char *get_i)//clears char array
{
	int i = get_size(get_i);
	i--;
	while(i>=0)
	{
		get_i[i] = '\0';
		i--;
	}
}
char* my_strcat(char* destination, const char* source)//concatenates char array from a char array
{
	char* ptr = destination + strlen(destination);
	while (*source != '\0')
		*ptr++ = *source++;
	*ptr = '\0';
	return destination;
}
char* my_strcat(char* destination, string source)//concatenates char array from a string
{
	char* ptr = destination + strlen(destination);
	int i = 0, j = get_size(destination);
	while(i<source.length())
	{
		destination[j] = source[i];
		i++;j++;
	}
	return destination;
}
char* strcpy_char_string(char* destination, string source)//concatenates char array from a string array from 0th index
{
	char* ptr = destination + strlen(destination);
	int i = 0, j = 0;
	while(i<source.length())
	{
		destination[j] = source[i];
		i++;j++;
	}
	return destination;
}
string ls(const char *path)//returns output of ls in a string
{
	using FilePtr = unique_ptr<FILE, decltype(&::pclose)>;
	string cmd("/bin/ls ");
	cmd.append(path);
	FilePtr ls(::popen(cmd.c_str(), "r"), ::pclose);
	if (ls == nullptr)
		return string();
	vector<char> buf(1024);
	string ret;
	while (::fgets(buf.data(), buf.size(), ls.get()))
		ret.append(buf.data());
	return ret;
}
void execute_change_directory(char* path_to_change)//executes change directory command
{
	int i = 0;
	string ls_ = ls(current_working_directory);
	if(strcmp(path_to_change, "cd") &&strcmp(path_to_change, "cd /")&&strcmp(path_to_change, "cd ..")&&strcmp(path_to_change, "cd ~") )
	{
		int partial_integer= 0;
		check_char_for_occurence(path_to_change, '/', partial_integer);
		path_to_change = &path_to_change[3];
		if(partial_integer == 0)
		{
			std::size_t found = ls_.find(path_to_change);
			if (found!=std::string::npos)
			{
				my_strcat(current_working_directory,"/");
				my_strcat(current_working_directory,path_to_change);
			}
			else {cout<<"No Directory by the name of "<<path_to_change<<" is present."<<endl;return;}
		}
		else 
		{
			string a_[partial_integer+1];
			partial_integer++;
			check_for_pipes(path_to_change, a_, partial_integer, '/');
			char alpha[100];
			strcpy_char_char(alpha, current_working_directory);
			for (int i = 0; i < partial_integer; i++)
			{
				string ls__ = ls(alpha);
				std::size_t found = ls__.find(a_[i]);
				if (found==std::string::npos)
				{
					cout<<"No Directory by the name of "<<a_[i]<<" is present."<<endl;
					cout<<"Try ls-- for more information."<<endl;
					return;
				}
				strcat(alpha, "/");
				my_strcat(alpha, a_[i]);
			}
			for (int i = 0; i < partial_integer; i++)
			{
				my_strcat(current_working_directory,"/");
				const char *a = a_[i].c_str();
				my_strcat(current_working_directory,a);
			}
		}		
	}
	else if(!strcmp(path_to_change, "cd .."))
	{
		int partial_integer = 0;
		check_char_for_occurence(current_working_directory, '/', partial_integer);
		char alpha[100];
		get_till_occurence_no(current_working_directory, alpha, '/', partial_integer);
		strcpy_char_char(current_working_directory, alpha);

	}
	else if(!strcmp(path_to_change, "cd") ||!strcmp(path_to_change, "cd /")||!strcmp(path_to_change, "cd ~"))
	{
		char newPath[] = "/home";
		char * str3 = (char *) malloc(1 + strlen(newPath)+ strlen(username) );
		strcpy_char_char(str3, newPath);
		my_strcat(str3,"/");
		my_strcat(str3,username);
		strcpy_char_char(current_working_directory,str3);
	}
    cout<<endl<<current_working_directory<<endl;
}
bool is_present(char input[], char character)//checks a char array for occurence of a character
{
	int i = 0; 
	while(input[i]!='\0')
	{
		if(input[i] == character)
			return true;
			i++;
	}
	return false;
}
void get_till_occurence_no(char input_file[], char output_char[], char character , int index_number)//copies a array from another array till occurence of a character till a certain index
{
	int size = get_size(input_file);
	int partial_integer = 0;
	for (int i = 0 ; i < size; i++)
	{
		if(partial_integer == index_number)
			break;
		if(input_file[i] == character)
			partial_integer++;
		output_char[i] = input_file[i];
	}
}
void get_till(char input_file[],char out_put_char[], char character, int &occurence_no)//copies a array from another array till occurence of a character from a certain index
{
	int i = get_size(input_file);
	int k = 0;
	if(occurence_no != 0)
	{
		occurence_no++;
	}
	while(occurence_no < i)
	{
		if(input_file[occurence_no] == character)
		{
			return;
		}
		out_put_char[k] = input_file[occurence_no];occurence_no++;k++;
	}
	out_put_char[k] = '\0';
}
void get_till(char a[],string b, char n, int &j)//copies a string from another array till occurence of a character from a certain index
{
	int i = get_size(a);
	int k = 0;
	if(j != 0)
	{
		j++;
	}
	while(j < i)
	{
		if(a[j] == n)
		{
			return;
		}
		b[k] = a[j];j++;k++;
	}
	b[k] = '\0';
}
void print_till(char a[], int i )//prints a char array till a certain point
{
	for (int j = 0; j < i; j++)
	{
		cout<<a[j];
	}
}
void remove_spaces(char alpha[])//removes spaces from a char array from the start and the end
{
	int i = get_size(alpha);
	int j = 0;
	while(1)
	{
        if(alpha[j]!=' ')
        break;
		j++;
	}
	//j++;
	if(j!= 0)
	{
		alpha = &alpha[j];
	}
    i = i - j;
    int size = i;
    while(1)
	{
        if(alpha[size-1]!=' ')
        break;
		size--;
	}
    if(i!= size)
    {
        alpha[size] = '\0';
    }
}
string cat(const char *path)//returns output of cat in a string
{
	using FilePtr = std::unique_ptr<FILE, decltype(&::pclose)>;
	std::string cmd("/bin/cat ");
	cmd.append(path);

	FilePtr ls(::popen(cmd.c_str(), "r"), ::pclose);
	if (ls == nullptr)
		return std::string();

	vector<char> buf(1024);
	std::string ret;
	while (::fgets(buf.data(), buf.size(), ls.get()))
		ret.append(buf.data());

	return ret;
}

////////////////////////EXTRA 
void c_out_pdf(string str_1)//prints the entire pdf on the terminal
{
	fstream obj(str_1);
	string str;
	int i = 0;
	while(obj)
	{
		i++;
		getline(obj, str);
		cout<<str<<endl;
	}
	if(i == 0)
	cout<<"Please place Project.pdf in the same directory"<<endl;
}


void do_output(char get_i[], bool ampercent)// for cmd > file_name
{
	char command_[10];
		int i = 0;
		get_till(get_i, command_, '>', i);
		char _out[10];
		get_till(get_i, _out, '\0', i);
		int partial_int = 0;
		while(_out[partial_int] == ' ')
			partial_int++;
			if(partial_int > 0)
			{
				char* abc = &_out[partial_int];
				strcpy(_out, abc);
			}
			if(ampercent)
			{
				if(fork())
				{
					fstream obj((string)skipwhite(_out), ios::out);
					if(!obj)
					{
						cout<<BOLDRED<<"Please place the "<<RESET<<BOLDWHITE<<_out<<RESET<<BOLDRED<<" int the same directory"<<RESET<<endl;
						return;
					}
					else
					{
						int partial_integer = 0;
						obj<<GetStdoutFromCommand(skipwhite(command_), partial_integer);
						obj.close();
						obj.clear();
					}
					return;
				}
				else return;
			}
			else
			{
				fstream obj((string)skipwhite(_out), ios::out);
				if(!obj)
				{
					cout<<BOLDRED<<"Please place the "<<RESET<<BOLDWHITE<<_out<<RESET<<BOLDRED<<" int the same directory"<<RESET<<endl;
					return;
				}
				else
				{
					int partial_integer = 0;
					obj<<GetStdoutFromCommand(skipwhite(command_), partial_integer);
					obj.close();
					obj.clear();
				}
				return;
			}
}
void do_output_redirection(char get_i[], bool ampercent)//for ///cmd < input > output// cmd < input /// cmd > output < input
{
	DISABLE_SIGINT
		char cmd[20], input_from[20];
		char input_to[20];
		split_for_output_redirection(get_i, cmd, input_to, input_from, get_size(get_i));
		remove_spaces(input_to);
		remove_spaces(input_from);
		if(ampercent)
		{
			DISABLE_SIGINT
			if(!fork())
			{
				if(input_to[0] == '1')
				{
					execute_output_redirection(input_from, cmd);
					return;
				}
				else
				{
					execute_output_redirection(input_from, cmd, input_to);
				}
			}
			else
			{
				return;
			}
			
		}
		else
		{
			DISABLE_SIGINT
			if(input_to[0] == '1')
			{
				execute_output_redirection(input_from, cmd);
				return;
			}
			else
			{
				execute_output_redirection(input_from, cmd, input_to);
			}
		}
}
















////////////////////////MAIN WORKING IS HERE///////////////////
void execute_program(char* get_i)//executes the program
{

	/////////////////////////////variable declaration///////////////////////////////////////////////
	int pCommands = 11;
	bool ampercent = false;
	char* set_en_variable = NULL;
	char* value_to_set;
	char possibilities_of_command_line[11][10] ={"clear","pwd","ls","cd","environ","setenv","unsetenv","man","ps", "help", "top"};
	int i,  partial_integer = 0;
	for(i=0;i<pCommands;i++)	
		if	(!my_strcmp(possibilities_of_command_line[i],get_i) || (get_i[0]==possibilities_of_command_line[i][0] && get_i[1]==possibilities_of_command_line[i][1]))	
			break;
	////////////////////////////////////////////check for background execution
	if(get_i[get_size(get_i)-1] == '&')
	{
		ampercent = true;
		get_i[get_size(get_i)-1] = '\0';
	}
	/////////////////////////for output redirection///////////////////////////
	if(is_present(get_i,'<'))/// handles /////////cmd < input > output///////cmd < input 
	{
		do_output_redirection(get_i, ampercent);
		return;
	}
	if(!is_present(get_i, '<')&& is_present(get_i, '>'))
	{
		do_output(get_i, ampercent);		
		return;
	}
	
	////////////////////////////////////////////BONUS WORK///////////////////////////////////////////////////////
	if(!strcmp(get_i, "pdf"))
	{
		system("pdftotext Project-Description.pdf Project_to_text.txt");
		c_out_pdf("Project_to_text.txt");
		return;
	}
	if(!strcmp(get_i, "show parts"))
	{
		fstream obj("parts.txt");
			string str;
			while(obj)
			{
				i++;
				getline(obj, str);
				cout<<str<<endl;
			}
		return;
	}
	///////////////////////// Perform for pipes////////////////////////////////////////////////////////////
	if(check_char_for_occurence(get_i, '|', partial_integer))
	{
		if(partial_integer == 1)
		{
			DISABLE_SIGINT
			char b[10];
			int i = 0;// sort | ls
			get_till(get_i, b, '|', i);  // a b c d e f 
			b[i] = '\0';
			char c[10];
			get_till(get_i, c, '\0', i);
			
			int p[2];
			pipe(p);
			if (vfork() == 0)//child ls
			{
			DISABLE_SIGINT    // 0 is for stdin 1 stdout
				close(0); 
				close(p[0]);
				close(p[1]);
				dup(p[0]); 
				execlp(c,c, NULL);
			} 
			else // sort parent
			{
				wait(NULL);
					close(1); 
					close(p[0]);
					close(p[1]);
					dup(p[1]); 
					execlp(b,b, NULL);
			}
			return;
		}
		else
		{// sort | ls | cat | ps
		//return;
		printf("Did alot to implement, but sorry the shell isn't so inteligent this time :(\n");
		return;
	/*	DISABLE_SIGINT
			int num = partial_integer+1;
			char ** str = new char*[num];
			for (int  i= 0; i < num; i++)
			{
				str[i] = new char[10];
			}
			check_for_pipes(get_i, str, num, '|');
			for (int i = 0; i < num ; i++)
			{
				cout<<skipwhite( str[i])<<endl;
			}
			execvp(str[0], str);
			
			return;
			int p[2];
			pipe(p);
			for (int i = 0; i < partial_integer; i++)
			{
				if (vfork() == 0)//child ls
				{
				DISABLE_SIGINT    // 0 is for stdin 1 stdout
					close(0); 
					close(p[0]);
					close(p[1]);
					dup(p[0]); 
					char a[100];
					//strcpy_char_string(a, str[num]);
					cout<<a<<endl;
					//execlp(a,a, NULL);
				} 
				else if(num>=1 && vfork())
				{
						wait(NULL);
						close(1); 
						close(p[0]);
						close(p[1]);
						dup(p[1]); 
						char a[100];
						//strcpy_char_string(a, str[num-1]);
					//	execlp(a,a, NULL);
				}
				num -= 2;
				return;
			}*/
		}
		
	}
	
	////////////////////CHECKS FOR THE REST////////////////
	//clear
	if(i == 0)
	{
		screen_clear;
	}
	else if(i == 1)//prints cwd
	{
		if(ampercent)
		{
			pid_t child;
			child = fork();
			if(child == 0)
			{
				DISABLE_SIGINT
				printf("%s\n",current_working_directory);
			}
			else return;
		}
		else printf("%s\n",current_working_directory);
	}
	else if(i == 2)//print ls
	{
		DISABLE_SIGINT; 
		if(ampercent)
		{
			DISABLE_SIGINT; 
			pid_t child = fork();
			if(child == 0)
			{
				list_dir(current_working_directory);
			}
			else return;
		}
		else	list_dir(current_working_directory);
	}
	else if(i == 3)// executes cd command
	{
		execute_change_directory(get_i);
	}
	else if(i == 4)//environ
	{
		DISABLE_SIGINT; 
		if(ampercent)
		{
			if(!fork())
			{
				envrion_execute();
			}
			else return;
		}
		else envrion_execute();
	}
	else if(i == 5)//setenv
	{
		set_en_variable = &get_i[i+1];
		DISABLE_SIGINT; 
		if(set_en_variable[0] == '\0')
		{
			if(ampercent)
			{
				DISABLE_SIGINT; 
				if(!fork())
				{
						envrion_execute();
						return;
				}
				else return;
			}
			else 	envrion_execute();
			return;
		}
		for(int i=7 ; get_i[i]!='\0' ; i++)
		{
			if(get_i[i] == ' ')
			{
				get_i[i] = '\0';
				value_to_set = &get_i[i+1];
				break;
			}
		}
		if(ampercent)
		{
			if(!fork())
			{
				DISABLE_SIGINT 
				setenv(set_en_variable,value_to_set,1);
				memset(set_en_variable, 0, sizeof (set_en_variable));
			}
			else
			{
				return;
			}
			
		}
		else
		{
			DISABLE_SIGINT 
			setenv(set_en_variable,value_to_set,1);
			memset(set_en_variable, 0, sizeof (set_en_variable));
		}
		
		
	}
	else if(i == 6)//unsetenv
	{
		DISABLE_SIGINT
		set_en_variable = &get_i[i+2];
		if(ampercent)
		{
			DISABLE_SIGINT
			if(!fork())
			{
				cout<<set_en_variable<<" "<<value_to_set<<endl;
				unsetenv(set_en_variable);
			}
			else
				return;
		}
		else
		{
				cout<<set_en_variable<<" "<<value_to_set<<endl;
				unsetenv(set_en_variable);
		}
	
	}
	else if(i == 7)//man
	{
		DISABLE_SIGINT
		int j = 0;
		string str = GetStdoutFromCommand((string)get_i, j);
		string get;
		const void * a = str.c_str();
		write(1,a, j);
		while(1)
		{
			cin>>get;
			if(get == "q")
			return;
		}

	}
	else if(i == 8)//for top, ps, 
	{
		DISABLE_SIGINT
		system(get_i);
	}
	else if(i == 9)/////////////////////BONUS WORK/////////////////////////////////
	{
		DISABLE_SIGINT
		//cout<<BOLDGREEN<<"PRESS "<<RESET<<BOLDRED<<"clear"<<RESET<<BOLDGREEN<<" TO CLEAR THE SCREEN"<<endl<<RESET;
		cout<<BOLDWHITE<<"PRESS "<<RESET<<BOLDRED<<"man"<<RESET<<BOLDWHITE<<" TO SEE THE MANUAL"<<endl<<RESET;
		cout<<BOLDWHITE<<"PRESS "<<RESET<<BOLDRED<<"pdf"<<RESET<<BOLDWHITE<<" TO SEE THE ENTIRE PDF ON THE TERMINAL"<<endl<<RESET;
		cout<<BOLDWHITE<<"PRESS "<<RESET<<BOLDRED<<"clear"<<RESET<<BOLDWHITE<<" TO CLEAR THE SCREEN"<<endl<<RESET;
		cout<<BOLDWHITE<<"PRESS "<<RESET<<BOLDRED<<"show parts"<<RESET<<BOLDWHITE<<" TO SEE THE PARTS WITH THEIR MARKS ON THE TERMINAL"<<endl<<RESET;
		cout<<BOLDWHITE<<"PRESS "<<RESET<<BOLDRED<<"top"<<RESET<<BOLDWHITE<<" TO SEE ALL THE PROCESSES"<<endl<<RESET;
		cout<<BOLDWHITE<<"PRESS "<<RESET<<BOLDRED<<"pwd"<<RESET<<BOLDWHITE<<" TO KNOW THE DIRECTORY"<<endl<<RESET;
		cout<<BOLDWHITE<<"PRESS "<<RESET<<BOLDRED<<"exit"<<RESET<<BOLDWHITE<<" TO QUIT THE PROCESS"<<endl<<RESET;
		cout<<BOLDWHITE<<"PRESS "<<RESET<<BOLDRED<<"ls"<<RESET<<BOLDWHITE<<" TO KNOW THE FILES PRESENT IN THE CURRENT DIRECTORY"<<endl<<RESET;
		cout<<BOLDWHITE<<"PRESS "<<RESET<<BOLDRED<<"cd"<<RESET<<BOLDWHITE<<" TO CHANGE DIRECTORY"<<endl<<RESET;
		cout<<BOLDWHITE<<"PRESS "<<RESET<<BOLDRED<<"environ"<<RESET<<BOLDWHITE<<" TO KNOW THE ENVIROMENTAL VARIABLES"<<endl<<RESET;
		cout<<BOLDWHITE<<"PRESS "<<RESET<<BOLDRED<<"setven"<<RESET<<BOLDWHITE<<" TO SET A ENVIROMENTAL VARIABLE"<<endl<<RESET;
		cout<<BOLDWHITE<<"PRESS "<<RESET<<BOLDRED<<"unsetenv"<<RESET<<BOLDWHITE<<" TO UNDO ALL THE ENVIROMENTAL VARIABLES THAT HAVE BEEN CHANGED"<<endl<<RESET;
		cout<<BOLDWHITE<<"WE ARE VERY SORRY "<<RESET<<BOLDRED<<"TO SAY"<<RESET<<BOLDWHITE<<" THAT NONE OF THE SIGINT WILL"<<endl<<RESET;
		cout<<BOLDWHITE<<"RESULT IN THE "<<RESET<<BOLDRED<<"SUDDEN"<<RESET<<BOLDWHITE<<" EXECUTION OF THE PROGRAM"<<endl<<RESET;
	}
	else if(i == 10)
	{
		DISABLE_SIGINT
		system(get_i);
	}
	else if(!strcmp(get_i, "cat"))////////cat/////////BONUS WORK/////////////////
	{
		cout<<cat(current_working_directory);
	}
	else ///////////INCORRECT STATEMENT
	{
		if(ampercent)
		{
			if(!fork())
			{
				cout<<BOLDYELLOW<<"ERROR : incorrect / non-existent command.\n"<<RESET<<endl;
			}
			else
			{
				return;
			} 
		}
		else
		{
			cout<<BOLDYELLOW<<"ERROR : incorrect / non-existent command.\n"<<RESET<<endl;
		}
	}
}