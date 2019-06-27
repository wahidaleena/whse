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
void queries()
{
    mysql_query(mysql,"SELECT item_nbr, movement_status, storage_location FROM Received_Items where movement_status = 'pending'");
    mysql_query(mysql,"SELECT COUNT(CustomerID), Country FROM Customers GROUP BY Country;SELECT AVG(Price)FROM Products");
    mysql_query(mysql,"SELECT * From Customers WHERE Name LIKE 'Herb%'");
    mysql_query(mysql,"INSERT INTO Yearly_Orders SELECT * FROM Orders WHERE Date<=1/1/2018");
    mysql_query(mysql,"SELECT Orders.OrderID, Customers.CustomerName, Orders.OrderDate FROM Orders INNER JOIN Customers ON Orders.CustomerID=Customers.CustomerID");
    mysql_query(mysql,"SELECT ROLL_NO,NAME FROM Student WHERE ROLL_NO>3 UNION ALL SELECT ROLL_NO,Branch FROM Student_Details WHERE ROLL_NO<3 ORDER BY 1");
    mysql_query(mysql,"SELECT COUNT (DISTINCT SIZE_DESC) INTO   ZERO FROM SSITMURX IRX, SSITMXRF IUX, MERTLDFT RTL WHERE  RTL.USERID  = XF_USERIDAND  RTL.TYPE =  'R'AND  IRX.CORP_ITEM_CD = MEX7_CORP_ITEM_CD AND  IRX.UNIT_TYPE    = MEX7_UNIT_TYPE AND  IRX.UPC_MANUF    = PRX_CURR_UPC_MANUF AND  IRX.UPC_SALES    = PRX_CURR_UPC_SALES AND  IRX.UPC_COUNTRY  = PRX_CURR_UPC_COUNTRY AND  IRX.UPC_SYSTEM   = PRX_CURR_UPC_SYSTEM AND  RTL.PA_ROG       =  IRX.ROG AND  IUX.CORP_ITEM_CD =  IRX.CORP_ITEM_CD AND  IUX.UPC_MANUF    =  IRX.UPC_MANUF AND  IUX.UPC_SALES    =  IRX.UPC_SALES AND  IUX.UPC_COUNTRY  =  IRX.UPC_COUNTRY AND  IUX.UPC_SYSTEM   =  IRX.UPC_SYSTEM AND (IRX.ROG = CASE WHEN WS_ROGS_WS_ROGS01 <> ' ' THEN WS_ROGS_WS_ROGS01 ELSE '    ' END OR  IRX.ROG = CASE WHEN WS_ROGS_WS_ROGS02 <> ' ' THEN WS_ROGS_WS_ROGS02 ELSE '    ' END OR  IRX.ROG = CASE WHEN WS_ROGS_WS_ROGS03 <> ' ' THEN WS_ROGS_WS_ROGS03 ELSE '    ' END OR  IRX.ROG = CASE WHEN WS_ROGS_WS_ROGS04 <> ' ' THEN WS_ROGS_WS_ROGS04 ELSE '    ' END OR  IRX.ROG = CASE WHEN WS_ROGS_WS_ROGS05 <> ' ' THEN WS_ROGS_WS_ROGS05 ELSE '    ' END OR  IRX.ROG = CASE WHEN WS_ROGS_WS_ROGS06 <> ' ' THEN WS_ROGS_WS_ROGS06 ELSE '    ' END OR  IRX.ROG = CASE WHEN WS_ROGS_WS_ROGS07 <> ' ' THEN WS_ROGS_WS_ROGS07 ELSE '    ' END OR  IRX.ROG = CASE WHEN WS_ROGS_WS_ROGS08 <> ' ' THEN WS_ROGS_WS_ROGS08 ELSE '    ' END OR  IRX.ROG = CASE WHEN WS_ROGS_WS_ROGS09 <> ' ' THEN WS_ROGS_WS_ROGS09 ELSE '    ' END OR  IRX.ROG = CASE WHEN WS_ROGS_WS_ROGS10 <> ' ' THEN WS_ROGS_WS_ROGS10 ELSE '    ' END OR  IRX.ROG = CASE WHEN WS_ROGS_WS_ROGS11 <> ' ' THEN WS_ROGS_WS_ROGS11 ELSE '    ' END OR  IRX.ROG = CASE WHEN WS_ROGS_WS_ROGS12 <> ' ' THEN WS_ROGS_WS_ROGS12 ELSE '    ' END OR  IRX.ROG = CASE WHEN WS_ROGS_WS_ROGS01 =  '    ' AND WS_ROGS_WS_ROGS02 =  '    ' AND WS_ROGS_WS_ROGS03 =  '    ' AND WS_ROGS_WS_ROGS04 =  '    ' AND WS_ROGS_WS_ROGS05 =  '    ' AND WS_ROGS_WS_ROGS06 =  '    ' AND WS_ROGS_WS_ROGS07 =  '    ' AND WS_ROGS_WS_ROGS08 =  '    ' AND WS_ROGS_WS_ROGS09 =  '    ' AND WS_ROGS_WS_ROGS10 =  '    ' AND WS_ROGS_WS_ROGS11 =  '    ' AND WS_ROGS_WS_ROGS12 =  '    ' THEN RTL.PA_ROG END) QUERYNO 5 ");
}
