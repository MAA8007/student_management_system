#include<iostream>
#include<iomanip>
#include<vector>
#include<string.h>
using namespace std;
int num_hostel= 600;
int active1 = 0;
int fixed22 = 30000;
string endgame = "x97mnop";
void host_display(int hostel[][2], string building[], int find,int id);
void hostel_student(int hostel_array [][2] ,string hostel_building_array [],  int id, int i, int finance[][4]);
void finca(int finance[][4], int find1);
void box(string h);
void notification(int find1, bool enquiry[][2], int finance[][4]);
void addss(double students[][7][10], int find1, double codes1[6], int finance[][4]);
void removess(double students[][7][10],double codes[6], int find1, int finance[][4]);
void passer(string passwords[], int number);
void initialise(double students[][7][10],string passwords[], int size, double codes[6], double ids[], int finance[][4]);
void student_acadamics(double students[][7][10], int size,string codes1[6],double codes2[6], double id, int finding, int finance[][4]);
double check_id(double students[][7][10],string password[], int batch_size, int& finding);
int checkid2(double students[][7][10], int size);
int checkcode(double students[][7][10], int find1);
void make_change(double students[][7][10], int find1, int find2);
void checkcode2(double students[][7][10], int find1, int find2,double codes[6]);
void add_test(double students[][7][10], int find1, int find2, int start);
void addcourse(double students[][7][10], int c1, int c2, double codes[6],int finance[][4]);
void academic(double students[][7][10], int batch_size, double codes1[6], int finance[][4]);
void shoes(double students[][7][10], bool enquiry[][2], int batch_size);
int checkid2(double students[][7][10], int size);
void proccess(vector<vector<string>>& queries, bool enquiry[][2], double students[][7][10], int batch_size);
void query_student(double ids[], int size1, vector<vector<string>>& queries, double id, bool enquiry[][2]);
void queryi(double students[][7][10], int size, bool enquiry[][2], vector<vector<string>>& queries);
int main()
{
    bool first = true;
    const int courses = 7;
    const int tests = 10;
    int batch_size;
    cout<<"how many students have we got this year? ";
    cin>>batch_size;
    double ids[batch_size];
    string passwords[batch_size];
    double students[batch_size][courses][tests];
    string codes1[6];
    double codes2[6];
    vector<vector<string>> queries(batch_size);
    int finance[batch_size][4];
    int hostel[batch_size][2];
    string building[batch_size];
    for(int i = 0; i < batch_size; i++)
    {
        for(int j = 0; j < 4; j++)
        {
        finance[i][j] = 0;
        } 
    }
    bool enquiry[batch_size][2];
    for(int j = 0; j < 2; j++)
    {
        for(int i = 0; i < batch_size; i++)
        {
            enquiry[i][j] = false;
        }
    }
    cout<<"this year we are offering "<<6<<" courses.\nplease enter names and respective codes of these course.\n";
    for(int i = 0; i < 6; i++)
    {
        cout<<"enter course name: ";
        cin>>codes1[i];
        bool co = true;
        while(co)
        {
        cout<<"enter course's code:";
        cin>>codes2[i];
        if(cin.fail() || codes2[i] < 0)
        {
            cin.clear();
            cin.ignore(10000,'\n');
            cout<<"wrong input:\n";
        }
        else{co = false;}
        }
        co = true;
    }
    
    initialise(students,passwords, batch_size, codes2, ids, finance);
    
    while(first)
    {
    cout<<"\n-------------\n";
    cout<<"s) student\ni) instructor\ne) exit\nenter:  ";
    char ne32;
    cin>>ne32;
    if(ne32 == 's')
    {
        bool hum;
        int finding = 0;
        double id = check_id(students ,passwords,batch_size, finding);
        if(id < 0)
        {
            hum = false;
        }
        else{
            notification(finding, enquiry, finance);
            hum = true;}
        while(hum)
        {
        
        cout<<"\n------------\n";
        cout<<"a) queries\nb) academics\nc) change password\nd) add hostel\ne) check hostel\nf) finance\ng) exit\nenter: ";
        char ne33;
        cin>>ne33;
        if(ne33 == 'a')
        {
            query_student(ids, batch_size,queries, id, enquiry);

        }
        else if(ne33 == 'b')
        {
            student_acadamics(students,batch_size, codes1, codes2,id,finding,finance);
        }
        else if(ne33=='c')
        {
            passer(passwords,finding);
        }
        else if(ne33 == 'd')
        {
            hostel_student(hostel, building, id, finding, finance);
        }
        else if(ne33 == 'e')
        {
            host_display(hostel,building,finding,id);

        }
        else if(ne33 == 'f')
        {
            finca(finance,finding);
        }
        else if(ne33 == 'g')
        {
            hum = false;
        }
        else{cout<<"invalid input:\n";}
        }
    }
    else if(ne32 == 'i')
    {
        bool hum6;
        string pass;
        cout<<"-----------------------\n";
        cout<<"enter password: ";
        cin>>pass;
        if(pass == endgame)
        {
            hum6 = true;
        }
        else
        {
            cout<<"incorrect password:\n";
            hum6 = false;
        }
        while(hum6){
        cout<<"\n------------\n";
        cout<<"a) queries\nb) academics\nc) exit\nenter: ";
        char ne33;
        cin>>ne33;
        if(ne33 == 'a')
        {
            queryi(students,batch_size,enquiry, queries);

        }
        else if(ne33 == 'b')
        {
        academic(students,batch_size,codes2,finance);
        }
        else if(ne33 == 'c')
        {
            hum6 = false;
        }
        else{cout<<"invalid input:\n";}
        }
    }
    else if (ne32 == 'e')
    {
        char g;
        cout<<"---------------------------------------------------------------------------------\n";
        cout<<"this will remove all of the data, do you wish to continue. (enter 'y' if yes): ";
        cin>>g;
        if(g == 'y')
        {
            cout<<"enter the password: ";
            string pass;
            cin>>pass;
            if(pass == endgame)
            {
                return 0;
            }
            else{cout<<"--------------------\n"<<"invalid password.\nrequest denied\n";
                 cout<<"--------------------\n";}

        }
        
    }
    else{cout<<"invalid input:\n";}
    }
}

//the folowing function allows the admin to initialise the student ID's, subjects, assignments/exams etc. 
void initialise(double students[][7][10],string passwords[], int size, double codes[6], double ids[], int finance[][4])
{
 
    int c1 = 0;
    int c2 = 0;
    int c3 = 0;
    bool check1 = true;
    bool check2;
    bool check3;
    while(check1)
    {
        check2 = false;
        char y1;
        cout<<"------------------------------------------------------\n";
        cout<<"do you want to enter a student id: (press'y' if yes)";
        cin>>y1;
        
        
        // entering a name(checks)
        if(y1 == 'y')
        {
            bool local1 = true;
            while(local1)
            {     
            cout<<"the student id: ";       
            cin>>students[c1][c2][c3];
            if(cin.fail() || students[c1][c2][c3] < 0)
            {
                cin.clear();
                cin.ignore(10000, '\n');
                cout<<"incorrect, you will be propmted again.\n";
            }
            else

            {
                local1 = false;
                ids[active1] = students[c1][c2][c3];
                cout<<"enter password for this id: ";
                cin>>passwords[c1];
                //passwords[c1] = to_string(students[c1][c2][c3]);
                active1++;
            }
            }

            check2 = true;
        }
        else
        {
            cout<<"let us move to the next section shall we?\n";
            check1 = false;
            students[c1][c2][c3] = -1;
        }
        while(check2)
        {
            check3 = false;
            char y2;
            cout<<"----------------------------------------------------\n";
            cout<<"do you want to enter a subject? (press 'y' if yes) ";
            cin>>y2;
            if(y2 == 'y' && c2 < 7)
            {
                check3 = true;
                c2++;
                students[c1][c2][7] = 0;
                students[c1][c2][8] = 0;
                bool local2 = true;
                while(local2)
                {
                
                cout<<"enter the subject code: ";
                cin>>students[c1][c2][c3]; 
                if(cin.fail() ||  students[c1][c2][c3] < 0)
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout<<"incorrect, you will be prompted again\n";
                }
                else{local2 = false;}
                }
                bool local4 = true;
                while(local4)
                {
                for(int i = 0; i < 6; i++)
                {
                    if(students[c1][c2][c3] == codes[i])
                    {
                        local4 = false;
                        break;
                    }
                }
                if(local4)
                {
                    cout<<"the code is incorrect\nplease enter another code\ncourse code:";
                    cin>>students[c1][c2][c3];
                }
                
                }
                finance[c1][0] += fixed22;
                finance[c1][1]++;
            }
            else
            {
                cout<<"\n--------------------------------------------------------\n";
                check2 = false;
                c2++;
                students[c1][c2][c3] = -1;
            }
            while(check3)
            {
                char y3;
                cout<<"-----------------------------------------------\n";
                cout<<"want to add an aasignment? (enter 'y' if yes)";
                cin>>y3;
                if(y3 == 'y')
                {
                    bool local3 = true;
                    c3++;
                    while(local3)
                    {
                    cout<<"enter the assignment marks: ";
                    cin>>students[c1][c2][c3];
                    if(cin.fail() || students[c1][c2][c3] < 0)
                    {
                        cin.clear();
                        cin.ignore(10000,'\n');
                        cout<<"incorrect, you will be prompted again\n";
                    }
                    else{local3 = false;}
                    }
                }
                else
                {
                    c3++;
                    students[c1][c2][c3] = -1;
                    check3 = false;
                    cout<<"\n-------------------------------------------------------\n ";
                    double sum = 0;
                    for(int i = 1; i < 6 && students[c1][c2][i] > -1; i++)
                    {
                        sum += students[c1][c2][i];  
                    }
                    if(c3 - 1 > 0){students[c1][c2][6] = sum/(c3-1);}
                    else{students[c1][c2][6] = 0;}
                    students[c1][c2][9] = (students[c1][c2][6] / 100)*30 + (students[c1][c2][7] / 100)*30 + (students[c1][c2][8] / 100)*40;
                    c3 = 0;
                }
                if(c3 == 5)
                {
                    check3 = false;
                    cout<<"\n----------------------------------------------------------\n";
                    c3 = 0 ;
                }
            
            }
            if(c2 == 6)
            {
                cout<<"\n----------------------------------------------------\n";
                check2 = false;
            }


        }
        c1++;
        if(c1 == size)
        {
            cout<<"\n-------------------------------------------------------\n";
            check1 = false;
        }
        c2 = 0;
        c3 = 0;
    
    }
}


//the folowing function allows a student to view  and manipulate their respective course realated data (e.g, add subjects etc)
void student_acadamics(double students[][7][10], int size,string codes1[6],double codes2[6],double id, int finding, int finance[][4])
{
    char choice;
    bool hum2 = true;
    int finding2;
    /*for(int i = 0;  i < size; i++ )
        {
            if(id == students[i][0][0])
            {
                finding = i;
                break;
            }

        }*/
    while(hum2)
    {
    cout<<"-------------------------------------------------------\n";
    cout<<"a) to see marks for all of your subjects.\nb) if you want to chose a particular subject\nc) add a course\nd) drop a course\ne) exit\nenter: ";
    cin>>choice;
   
    if(choice == 'a')
    {   cout<<"---------------------\n";
        cout<<"student id: "<<id<<endl;
        cout<<"---------------------\n";
        if(students[finding][1][0] == -1)
        {
            cout<<"there is nothing to show, your not enrolled in any of the courses yet\n";
            return;
        }
        
        for(int i = 1; i < 7 && students[finding][i][0] >= 0; i++)
        {
            string subject;
            for(int j = 0; j < 6; j++)
            {
                if(codes2[j] == students[finding][i][0])
                {
                    subject = codes1[j];
                    break;
                }
            }
            cout<<"subject: "<<subject<<endl;
            for(int j = 1; j < 6 && students[finding][i][j] >= 0; j++)
            {
                cout<<"assignment "<<j<<" "<<students[finding][i][j]<<"%"<<endl;
            }
            cout<<"grade percentage (assignments): "<<students[finding][i][6]<<endl;
            cout<<"grade percentage (mid terms): "<<students[finding][i][7]<<endl;
            cout<<"grade percentage (final exams): "<<students[finding][i][8]<<endl;
            cout<<"grade percentage (total): "<<students[finding][i][9]<<endl;
            cout<<"-----------------------------------\n\n";
        }
    }
    else if(choice == 'b')
    {
        if(students[finding][1][0] < 0){cout<<"nothing to show yet:\n"; return;}
        bool original = true;
        while(original)
        {   
        cout<<"\n------------------------------------------\n";
        cout<<"courses you are currently enrolled in are:\n"<<setw(15)<<"courses"<<"|"<<setw(10)<<"codes\n";
        for(int i = 1; i < 7 && students[finding][i][0] >= 0; i++)
        {
            for(int j = 0; j < 6; j++)
            {
                if(codes2[j] == students[finding][i][0])
                {
                    cout<<setw(15)<<codes1[j]<<"|"<<setw(10)<<codes2[j]<<endl;
                    for(int i =0; i < 26;i++)
                    {
                        cout<<"-";
                    }
                    cout<<endl;
                    
                }
            }
        }
        double code;
        bool locally = true;
        while(locally)
        {
        cout<<"enter the code of course you want to see: ";
        cin>>code;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(10000,'\n');
        }
        else
        {
            for(int i = 1; i < 7 && students[finding][i][0] > -1; i++)
            {
                if(code == students[finding][i][0])
                {
                    locally = false;
                    finding2 = i;
                    break;
                }
            }
            if(locally){cout<<"incorrect input, you will be prompted again.\n";}
        }
        }
            cout<<"---------------------\n";
        for(int j = 1; j < 6 && students[finding][finding2][j] >= 0; j++)
            {
                cout<<"assignment "<<j<<" "<<students[finding][finding2][j]<<"%"<<endl;
            }
            cout<<"grade percentage (assignments): "<<students[finding][finding2][6]<<"%"<<endl;
            cout<<"grade percentage (mid terms): "<<students[finding][finding2][7]<<"%"<<endl;
            cout<<"grade percentage (final exam): "<<students[finding][finding2][8]<<"%"<<endl;
            cout<<"grade percentage (total) "<<students[finding][finding2][9]<<"%"<<endl;
            cout<<"---------------------\n";
            cout<<"want to see any other subject? (press 'y' if yes)\n";
            char ch;
            cin>>ch;
            if(ch!='y'){original = false;}
        }
    }
    else if(choice == 'c')
    {
        addss(students,finding,codes2, finance);
    }
    else if(choice == 'd')
    {
        removess(students,codes2,finding, finance);
    }
    else if(choice == 'e'){hum2 = false;}
    else{cout<<"invalid input:\n";}
    }

}
double check_id(double students[][7][10],string passwords[], int batch_size, int& finding)
{
    double id;
bool local1 = true;
    while(local1)
    {
        cout<<"------------------------------\n";
        cout<<"please enter your zambeel id: ";
        cin>>id;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(10000,'\n');
        }
        else
        {
            for(int i =0; i < batch_size; i++ )
            {
                if(id == students[i][0][0] )
                {
                    local1 = false;
                    string pass;
                    cout<<"please enter your password: ";
                    cin>>pass;
                    if(pass != passwords[i])
                    {
                        cout<<"wrong password:\n";
                        local1 = true;
                    }
                    finding = i;
                    break;
                }
            }
            if(local1){cout<<"You will be prompted again:\n";}
           
            if(local1){
            char yy;
            cout<<"do you want to continue? (press 'y' if yes)";
            cin>>yy;
            if(yy!='y'){local1 = false;
            return-1;}}
            if(local1){cout<<"----------------------------\n";
            cout<<"You will be prompted again:\n";}
        }
    }
    return id;
    // introduce password;
}


//the folowing function allows the instructor to change and/or add new data to each student's profile 
void academic(double students[][7][10], int batch_size, double codes1[6], int finance[][4])
{
    bool hum3 = true;
    int find1;
    int find2;
    char y1;
    while(hum3)
    {
    cout<<"---------------------------\n";
    cout<<"a) change in exiting data\nb) add new data\nc) exit\nenter: ";
    cin>>y1;
    
    // existing data
    if(y1 == 'a')
    {
        bool hum4 = true;
        while(hum4)
        {
        cout<<"--------------------------\n";    
        cout<<"\na) change in assignments\nb) change in courses\nc) remove course\nd) exit\nenter: ";
        char y2;
        cin>>y2;
        // assignment change
        if(y2 == 'a')
        {
            find1 = checkid2(students, batch_size);
            if(students[find1][1][0] < 0){
                cout<<"no courses to make change in:\n";
                return;
            }
            find2 = checkcode(students,find1);
            make_change(students,find1,find2);

        }
        // course change
        else if(y2=='b')
        {
            find1 = checkid2(students, batch_size);
            if(students[find1][1][0] < 0){
                cout<<"no courses to make change in:\n";
                return;
            }
            find2 = checkcode(students, find1);
            checkcode2(students,find1,find2,codes1);
            add_test(students, find1, find2, 1);
        }
        else if(y2 == 'c')
        {
            // removing course
            find1 = checkid2(students, batch_size);
            if(students[find1][1][0] < 0){
                cout<<"no courses to make change in:\n";
                return;
            }
            find2 = checkcode(students, find1);
            for(int i = find2; i < 6 ; i++)
            {
                for(int j =0; j < 10;j++)
                {
                    students[find1][i][j] = students[find1][i+1][j];
                }
            }
            students[find1][6][0] = -1;
            finance[find1][0] -= fixed22;
            finance[find1][1]--;
        }
        //
        else if(y2 == 'd'){hum4 = false;}
        else{cout<<"invalid input:\n";}
    }

    }
    else if(y1 == 'b')
    {
        bool hum5 = true;
        while(hum5)
        {
        char y7;
        cout<<"\n--------------------\n";
        cout<<"a) add a course\nb) add assignments\nc) add midterm marks\nd) add final exam marks\ne) exit\nenter: ";
        cin>>y7;

        if(y7 == 'a')
        // add courses
        {
            int find1 = checkid2(students, batch_size);
            int find2 = 0;
            for(int i = 1; i < 7 && students[find1][i][0] > -1; i++)
            {
                find2 = i;
            }
            if(find2 < 6)
            {
                addcourse(students, find1, find2,codes1,finance);

            }
            else{
                cout<<"you have already added maximum courses:\n";
            }
            

        }
        else if(y7 == 'b')
        // add assignments
        {
            int find1 = checkid2(students, batch_size);
            if(students[find1][1][0] < 0){cout<<"no courses exist as of yet:\n";return;}
            int find2 = checkcode(students,find1);
            int act = 1;
            for(int i = 1; i < 6 && students[find1][find2][i] > -1; i++)
            {
                act++;
            }
            add_test(students,find1,find2,act);

        }
        else if(y7 == 'c')
        {
            // add mid term marks;
            int find1 = checkid2(students, batch_size);
            if(students[find1][1][0] < 0)
            {
                cout<<"no course exists:\n";
            }
            else{
            int find2 = checkcode(students,find1);
            bool hello = true;
            while(hello)
            {
            cout<<"enter mid term marks: ";
            cin>>students[find1][find2][7];
            if(cin.fail() || students[find1][find2][7] < 0)
            {
                cout<<"invalid input:\n";
            }
            else{hello = false;}
            }
             students[find1][find2][9] = (students[find1][find2][6] / 100)*30 + (students[find1][find2][7] / 100)*30 + (students[find1][find2][8] / 100)*40;
        
            }
        }
        else if(y7 == 'd') 
        {
            // add final exam
            int find1 = checkid2(students, batch_size);
            if(students[find1][1][0] < 0)
            {
                cout<<"no course exists:\n";
            }
            else{
            int find2 = checkcode(students,find1);
            bool hello = true;
            while(hello)
            {
            cout<<"enter final exam marks: ";
            cin>>students[find1][find2][8];
            if(cin.fail() || students[find1][find2][7] < 0)
            {
                cout<<"invalid input:\n";
            }
            else{hello = false;}
            }
             students[find1][find2][9] = (students[find1][find2][6] / 100)*30 + (students[find1][find2][7] / 100)*30 + (students[find1][find2][8] / 100)*40;
            }
        }
        else if(y7 == 'e'){hum5 = false;}
        else{cout<<"invalid input:\n";}
        }
    }
    else if(y1 == 'c')
    {
        // to keep it running
        hum3 = false;
    }
    else{cout<<"incorrect input:\n";}
}
}    


//the folowing function is a validation check to ensure that invalid id has not been entered 
// check id
int checkid2(double students[][7][10], int size)
{
    int find1;
    bool local1 = true;
    while(local1)
    {
    double id;
    cout<<"---------------------------\n";
    cout<<"please enter a student id: ";
    cin>>id;
    if(cin.fail() || id < 0)
    {
        cin.clear();
        cin.ignore(10000,'\n');
        cout<<"wrong input, you will be prompted again.\n";
    }
    else
    {
        for(int i = 0; i < size && students[i][0][0] > -1; i++)
        {
            if(id == students[i][0][0])
            {
                find1 = i;
                local1 = false;
                break;
            }

        }
        if(local1){cout<<"wrong input.\n";}
    }
    }
    return find1;
}


//the folowing function is a code validation check  
int checkcode(double students[][7][10], int find1)
{
    
    bool local2 = true;
    double code;
    int find2;
    while(local2)
    {
        cout<<"courses available to this student are: \n";
        for(int i = 1; i < 7 && students[find1][i][0] > -1; i++)
        {
            cout<<students[find1][i][0]<<endl;
        }
    cout<<"enter course code to make changes in :";
    cin>>code;
    if(cin.fail() || code < 0)
    {
        cin.clear();
        cin.ignore(10000,'\n');
        cout<<"wrong input.\n";
    }
    else
    {
        for(int i = 1; i < 7 && students[find1][i][0] > -1; i++ )
        {
            if(students[find1][i][0] == code)
            {
                find2 = i;
                local2 = false;
                break;
            }
        }
        if(local2){cout<<"wrong input:\n";}

    }
    }
    return find2;
}
// 
//the folowing function allows the instructor to make changes in graded components
void make_change(double students[][7][10], int find1, int find2)
{
    int active = 0;
    for(int i = 1; i < 6 && students[find1][find2][i] > -1; i++)
    {
        active++;
    }
    if(active == 0){cout<<"no assignments for this course exist\n";return;}
    int test_no;
    bool local3 = true;
    while(local3)
    {
    cout<<"which assignment do you want to make a change in: ";
    cin>> test_no;
    if(cin.fail() || test_no < 1 || test_no > active)
    {
        cin.clear();
        cin.ignore(10000,'\n');
        cout<<"incorrect input.\n";
    }
    else{local3 = false;}
    }
    cout<<"enter the new score: ";
    cin>>students[find1][find2][test_no];
    double sum = 0;
    for(int i = 1; i <= active; i++)
    {
        sum += students[find1][find2][i];
    }
    students[find1][find2][6] = sum/active;
    students[find1][find2][9] = (students[find1][find2][6] / 100)*30 + (students[find1][find2][7] / 100)*30 + (students[find1][find2][8] / 100)*40;

}

//the folowing function is a code validation check 
void checkcode2(double students[][7][10], int find1, int find2,double codes[6])
{
    bool local5 = true;
    while(local5)
    {
    cout<<"please enter the new course's code: ";
    cin>>students[find1][find2][0];
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(10000,'\n');
        cout<<"wrong input you will be promted again.\n";
    }
    else
    {
        for(int i =0; i < 6; i++)
        {
            if(codes[i] == students[find1][find2][0])
            {
                local5 = false;
                break;
            }
        }
        if(local5){cout<<"wrong input, you will be prompted again.\n";}
    }


}
}

// 
//the folowing function allows instructor to add assignment after course change
void add_test(double students[][7][10], int find1, int find2, int start)
{
    for(int i = start; i < 10; i++)
    {
        students[find1][find2][i] = 0;
    }
    students[find1][find2][7] = 0;
    students[find1][find2][8] = 0;
    char y5;
    char y6;
    bool decide = false;
    bool decide2 = true;
    cout<<"do you want to add assignments for this course (enter 'y' if yes): ";
    cin>>y5;
    if(y5 == 'y'){decide = true;}
    int k = 5;
    for(int i = start; i < 6 && decide; i++) 
    {
        cout<<"do you want to add assignments (enter 'y' if yes): ";
        cin>>y6;
        if(y6 == 'y'){ decide2 = true;}
        else
        {
            decide = false;
            if(i < 6)
            {
            students[find1][find2][i] = -1;
            k = i;
            }       
            
        }
        while(decide2)
        {
            cout<<"enter the score: ";
            cin>>students[find1][find2][i];
            if(cin.fail() || students[find1][find2][i] < 0)
            {
                cin.clear();
                cin.ignore(10000, '\n');
                cout<<"wrong input, you will be prompted again.\n";
            }
            else{decide2 = false;}
        }
        
    }
    if(y5 == 'y')
    {
    double sum = 0;
    for(int i = 1; i <= k; i++)
    {
        sum += students[find1][find2][i];
    }
    students[find1][find2][6] = sum/k;
    students[find1][find2][9] = (students[find1][find2][6] / 100)*30 + (students[find1][find2][7] / 100)*30 + (students[find1][find2][8] / 100)*40;
    }
    if(start > 5){cout<<"you can not add more assignments.\n";}
}


//the folowing function alows teh instructor to add courses
void addcourse(double students[][7][10], int c1, int c2, double codes[6], int finance[][4])
{
bool check2 = true;
bool check3;
int c3 = 0;
while(check2)
        {
            check3 = false;
            char y2;
            cout<<"do you want to enter a subject? (press 'y' if yes) ";
            cin>>y2;
            if(y2 == 'y' && c2 < 6)
            {
                check3 = true;
                c2++;
                students[c1][c2][7] = 0;
                students[c1][c2][8] = 0;
                bool local2 = true;
                while(local2)
                {
                cout<<"enter the subject code: ";
                cin>>students[c1][c2][c3]; 
                if(cin.fail() ||  students[c1][c2][c3] < 0)
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout<<"incorrect, you will be prompted again\n";
                }
                else{local2 = false;}
                }
                bool local4 = true;
                while(local4)
                {
                for(int i = 0; i < 6; i++)
                {
                    if(students[c1][c2][c3] == codes[i])
                    {
                        local4 = false;
                        break;
                    }
                }
                if(local4)
                {
                    cout<<"the code is incorrect\nplease enter another code\ncourse code:";
                    cin>>students[c1][c2][c3];
                }
                }
                finance[c1][0] += fixed22;
                finance[c1][1]++;

            }
            else
            {
                cout<<"next section shall we? \n";
                check2 = false;
                c2++;
                students[c1][c2][c3] = -1;
            }
            while(check3)
            {
                char y3;
                cout<<"want to add an aasignment? (enter 'y' if yes)";
                cin>>y3;
                if(y3 == 'y')
                {
                    bool local3 = true;
                    c3++;
                    while(local3)
                    {
                    cout<<"enter the assignment marks: ";
                    cin>>students[c1][c2][c3];
                    if(cin.fail() || students[c1][c2][c3] < 0)
                    {
                        cin.clear();
                        cin.ignore(10000,'\n');
                        cout<<"incorrect, you will be prompted again\n";
                    }
                    else{local3 = false;}
                    }
                }
                else
                {
                    c3++;
                    students[c1][c2][c3] = -1;
                    check3 = false;
                    cout<<"oh we are done:\n ";
                    double sum = 0;
                    for(int i = 1; i < 6 && students[c1][c2][i] > -1; i++)
                    {
                        sum += students[c1][c2][i];  
                    }
                    if(c3 - 1 > 0){students[c1][c2][6] = sum/(c3-1);}
                    else{students[c1][c2][6] = 0;}
                    students[c1][c2][9] = (students[c1][c2][6] / 100)*30 + (students[c1][c2][7] / 100)*30 + (students[c1][c2][8] / 100)*40;
                    c3 = 0;
                }
                if(c3 == 5)
                {
                    check3 = false;
                    c3 = 0 ;
                }
            
            }
            if(c2 == 6)
            {
                cout<<"we are done: \n";
                check2 = false;
            }


        }
}


//the folowing function allows the instructor to view and respond to students' queries. 
void queryi(double students[][7][10], int size, bool enquiry[][2], vector<vector<string>>& queries)
{
    
    // show new messages
      bool alpha = true;
      while(alpha){
      shoes(students, enquiry, size);
      cout<<"\n---------------------------------\n";
      cout<<"a) start answering queries\nb) answer to a particular student\nc)leave\nenter: ";
      char y00;
      cin>>y00;
      cout<<endl;
      if(y00 == 'a')
      {
        //start answering queries
        proccess(queries, enquiry, students, size);

      }
      else if(y00 == 'b')
      {
        // answering to one person
       bool check = true;
       while(check)
       {
       cout<<"------------------------------------\n";
       int find1 = checkid2(students,size);
       cout<<"previous correspondence:\n";
       for(int i = 0; i < queries[find1].size(); i++)
       {
        box(queries[find1][i]);
       }
       cout<<"enter new message :";
       string buffer1 = "instructor: ";
       string buffer2;
       cin.ignore();
       getline(cin,buffer2);
       buffer1 += buffer2;
       queries[find1].push_back(buffer1);
       char y067;
       enquiry[find1][1] = false;
       enquiry[find1][0] = true;
       cout<<"do you want to message someone else (enter 'y' if yes): ";
       char y77;
       cin>>y77;
       if(y77 != 'y'){check = false;}
       }
    }
    else if(y00 == 'c'){return;}
    else{cout<<"invalid input: ";}
      }
}


//the folowing function displays unreponded queries to the instructor 
void shoes(double students[][7][10], bool enquiry[][2], int batch_size)
{
     bool exception = true;
    cout<<"\n------------------------------------------------------------\n";
    cout<<"below are all the student ids that have unresponded queries:\n";
    for(int i = 0; i < batch_size; i++)
    {
        if(enquiry[i][1] == true)
        {
        
            cout<<"|"<<students[i][0][0]<<setw(5)<<"|"<<endl;
            cout<<"-------";
            exception = false;
        }
    }
    if(exception){cout<<"no unresponded queries:\n\n";}

}


//the folowing function allows instructor to answer queries
void proccess(vector<vector<string>>& queries, bool enquiry[][2], double students[][7][10], int batch_size)
{
    string buffer1 = "instructor: ";
    string buffer2;
    bool faisla = false;
    bool cheese = true;
    for(int i = 0; i < batch_size; i++)
    {
        
        if(enquiry[i][1] == true)
        {
            cheese = false;
            char y09;
            cout<<"-----------------------------------------------------------------\n";
            cout<<"do you want to continue with answering queries (enter 'y' if yes)";
            cin>>y09;
            if(y09 != 'y'){break;}
            char y01;
            cout<<"do you want to correspond with id: "<<students[i][0][0]<<" (press 'y' if yes): ";
            cin>>y01;
            if(y01 == 'y')
            {
                for(int j = 0; j < queries[i].size(); j++)
                {
                  box(queries[i][j]);
                }
                cout<<"reply: ";
                cin.ignore();
                getline(cin,buffer2);
                buffer1 = buffer1 + buffer2;
                queries[i].push_back(buffer1);
                enquiry[i][1] = false;
                enquiry[i][0] = true;
            }
        }
        if(cheese){
            cout<<"-----------------------\n";
            cout<<"no unresponded queries.\n";}
       
    }
}

//the folowing function allows student to view and respond tio queries
void query_student(double ids[], int size1, vector<vector<string>>& queries, double id, bool enquiry[][2])
{
    string buffer;
    int finding1;
    for(int i = 0; i < size1; i++)
    {
        if(ids[i] == id)
        {
            finding1 = i;
            break;
        }
    }
    bool check2 = true;
    while(check2)
    {
    char check1;
    cout<<"\n-------------------------------------\n";
    cout<<"a) write a new query\nb) check on privious correspondence\nc) leave this tab\nenter:";
    cin>>check1;
    cout<<endl;
    string buffer2;
    if(check1 == 'a')
    {
        cout<<"-------------------------\n";
        cout<<"please enter your query: ";
        cin.ignore();
        getline(cin,buffer);
        buffer2 = "student: " + buffer;
        queries[finding1].push_back(buffer2);
        enquiry[finding1][1] = true;
        enquiry[finding1][0] = false;
        
    }
    else if(check1 == 'b')
    { 
        if(queries[finding1].size() == 0)
        {
            cout<<"----------------------\n";
            cout<<"no correspondense yet:\n";
        }
        else
        {
         for(int i = 0; i < queries[finding1].size(); i++)
        {
            box(queries[finding1][i]);
        }
        }
    }
    else if(check1 == 'c'){return;}
    else{cout<<"invalid input: \n";}
}
}

void box(string h)
{
    int n = h.length();
    for(int i = 0; i < n + 2; i++)
    {
        cout<<"-";
    }
    cout<<"\n|"<<h<<"|\n";
    for(int i = 0; i < n + 2; i++)
    {
        cout<<"-";
    }
    cout<<endl;
}


//the folowing function allows studnet ti change their password
void passer(string passwords[], int number)
{
    /*
    int number;
    for(int i = 0; i < batch_size; i++)
    {
        if(id == ids[i])
        {
            number = i;
            break;
        }
    }*/
    cout<<"--------------------------------------------------------\n";
    cout<<"please enter your new password: ";
    cin>>passwords[number];
}


//the folowing function allows an instructor/student to remove a course
void removess(double students[][7][10],double codes[6], int find1, int finance[][4])
{
            if(students[find1][1][0] < 0){
                cout<<"no courses to make change in:\n";
                return;
            }
   int find2 = checkcode(students, find1);
            for(int i = find2; i < 6 ; i++)
            {
                for(int j =0; j < 10;j++)
                {
                    students[find1][i][j] = students[find1][i+1][j];
                }
            }
            students[find1][6][0] = -1;
            finance[find1][0] -= fixed22;
            finance[find1][1]--;
}


//the folowing function allows studnet to add a course
void addss(double students[][7][10], int find1, double codes1[6], int finance[][4])
{
int find2 = 0;
            for(int i = 1; i < 7 && students[find1][i][0] > -1; i++)
            {
                find2 = i;
            }
            if(find2 < 6)
            {
            bool check3 = false;
            char y2;
            cout<<"do you want to enter a subject? (press 'y' if yes) ";
            cin>>y2;
            if(y2 == 'y' && find2 < 6)
            {
                check3 = true;
                find2++;
                students[find1][find2][7] = 0;
                students[find1][find2][8] = 0;
                bool local2 = true;
                while(local2)
                {
                cout<<"enter the subject code: ";
                cin>>students[find1][find2][0]; 
                if(cin.fail() ||  students[find1][find2][0] < 0)
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout<<"incorrect, you will be prompted again\n";
                }
                else{local2 = false;}
                }
                bool local4 = true;
                while(local4)
                {
                for(int i = 0; i < 6; i++)
                {
                    if(students[find1][find2][0] == codes1[i])
                    {
                        local4 = false;
                        break;
                    }
                }
                if(local4)
                {
                    cout<<"the code is incorrect\nplease enter another code\ncourse code:";
                    cin>>students[find1][find2][0];
                }
                }
                finance[find1][0] += fixed22;
                finance[find1][1]++;
            }
            if(find2 < 6)
            {
            students[find1][find2+1][0] = -1;
            }
            students[find1][find2][1] = -1;
            for(int i = 6; i <10; i++)
            {
                students[find1][find2][i] = 0;
            }
            
            }
            else{
                cout<<"you have already added maximum courses:\n";
            }
}


//the folowing function displays unattented notifications
void notification(int find1, bool enquiry[][2], int finance[][4])
{
    string a = "notifications: ";
    string b = "please clear your dues";
    string c = "you have a new message from the instructor";
    if(enquiry[find1][0] == true && finance[find1][0] != 0)
    {
        box(a);
        box(b);
        box(c);     
    }
    else if(enquiry[find1][0] == true)
    {
        box(a);
        box(c);
    }
    else if(finance[find1][0] != 0)
    {
        box(a);
        box(b);
    }



}


//the folowing function allows a studnet to view the finance portal 
void finca(int finance[][4], int find1)
{
    cout<<"----------------------------------\n";
    cout<<"course you are inrolled in are:"<<finance[find1][1]<<endl;
    cout<<"total cost of course: "<<finance[find1][1] * fixed22<<endl;
    cout<<"hostel charges: "<<finance[find1][2]<<endl;
    cout<<"total payable: "<<finance[find1][0]<<endl;
    cout<<"----------------------------------\n";
}


//the folowing function allows a studnet a hostel 
void hostel_student(int hostel_array [][2] ,string hostel_building_array [],  int id, int i, int finance[][4]){
    
    if(hostel_array[i][0] == id)
    {
        cout<<"--------------------------\n";
        cout<<"you already have a hostel:\n";
        return;
    }
    
    cout<<"Do you want a room? If yes, enter 'Y', else enter 'NO'";
    char room_req;
    cin>>room_req;
    if (room_req=='Y'){
        finance[i][2] = 60000;
        finance[i][0] += 60000;

    
                    if (num_hostel!=0){
                        int roomnum=num_hostel;
                        hostel_array[i][0]=id;
                        hostel_array[i][1]=roomnum;
                        num_hostel--;
                        cout<<"-----------------------------------------------------\n";
                        if(roomnum<=600 && roomnum >500){
                            cout<<"you have been alloted M1. Your room number is: "<<roomnum<<endl;
                            hostel_building_array[i]="M1";
                        }

                        else if(roomnum<500 && roomnum >400){
                            cout<<"you have been alloted M2. Your room number is: "<<roomnum<<endl;
                            hostel_building_array[i]="M2";
                        }

                        else if(roomnum<400 && roomnum >300){
                            cout<<"you have been alloted M3. Your room number is: "<<roomnum<<endl;
                            hostel_building_array[i]="M3";
                        }

                        else if(roomnum<300 && roomnum >200){
                            cout<<"you have been alloted M4. Your room number is: "<<roomnum<<endl;
                            hostel_building_array[i]="M4";
                        }

                        else if(roomnum<200 && roomnum >100){
                            cout<<"you have been alloted M5. Your room number is: "<<roomnum<<endl;
                            hostel_building_array[i]="M5";
                        }

                        else if(roomnum<100 && roomnum >0){
                            cout<<"you have been alloted M6. Your room number is: "<<roomnum<<endl;
                            hostel_building_array[i]="M6";
                        }
                        cout<<"-------------------------------------------------------------\n";
                    }
                    else{
                            cout<<"No hostels remaining\n";
                        }
                }
}


//the folowing function is a confirmation of hostel 
void host_display(int hostel[][2], string building[], int find,int id)
{
    cout << "-----------------------------------\n";
    if(hostel[find][0] != id)
    {
        cout<<"you dont have hostel allocation: \n";
        return;
    }
    cout<<"room number: "<<hostel[find][1]<<endl;
    cout<<"building: "<<building[find]<<endl;
}