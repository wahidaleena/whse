#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <mysql.h>
#include <stdlib>

using namespace std;

struct Data
{
    string i_num;
    string m_stat;
    string s_loc;
};

int main () {
  
                FILE *fp;
                struct Data d[100];
                char DB_NAME[1000],TABLE_NAME[1000],USER[1000],PASS[1000],FILEN[1000];
                
                strcpy(DB_NAME, getenv("DBNAME"));
                strcpy(TABLE_NAME, getenv("TABLENAME"));
                strcpy(USER, getenv("USERNAME"));
                strcpy(PASS, getenv("PASSWORD"));
                strcpy(HOST, getenv("HOST"));
                strcpy(FILENAME, getenv("FILENAME"));

                fp = fopen(FILENAME, "w");
                
                int j = 0;
                while (j<10)
                {
                                string i_num = d[j].i_num;
                                string stat = d[j].m_stat;
                                j++;
                }
                
                MYSQL mysql;
                status = connect2Mysql(mysql, HOST, USER, PASS, DB_NAME);

                if(status== True)
                {
                                updateDB(mysql,fp,d);
                                fprintf(fp, "UPDATE TABLE_NAME SET movement_status = %s WHERE item_nbr = %s", stat,i_num);
                }
                else
                {
                                updateFile(fp,d);
                }              

                fclose(fp);
                return 0;

}

bool connect2Mysql(MYSQL *mysql, char *HOST, char *USER, char *PASS, char *DB_NAME)
{
                bool status;
                mysql = mysql_init(NULL);
                mysql_real_connect(mysql, HOST, USER, PASS, DB_NAME, 0, 0, 0);
                return status;
}

void updateDB(MYSQL mysql,FILE *myfile,Data d)
{
                int j = 0;
                while (j<10)
                {
                                string i_num = d[j].i_num;
                                string stat = d[j].m_stat;
                                mysql_query(mysql, "UPDATE TABLE_NAME SET movement_status = stat WHERE item_nbr = i_num");
                                j++;
                }
                updateFile(myfile,d);
                
}

void updateFile(FILE *myfile,Data d)
{
                int i=0;
                
                while (myfile)
                {
                                getline(myfile, d[i].i_num, ',');
                                getline(myfile, d[i].m_stat, ',');
                                getline(myfile, d[i++].s_loc, '\n');
                }
}
