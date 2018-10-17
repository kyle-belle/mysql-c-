#include <stdio.h>
#include <winsock.h>
#include <mysql.h>

using namespace std;

int main()
{
    MYSQL* connection;
    MYSQL_RES* res;
    MYSQL_ROW row;

    const char* select_query = "SELECT * FROM customers";

    int query_error;

    connection = mysql_init(0);

    if(connection){
        printf("connection object is working\n");

        connection = mysql_real_connect(connection, "your host", "user account", "your password", "your database name", 0, nullptr, 0);

        if(connection){
            printf("connection to database %s successful\n", connection->db);

            query_error = mysql_query(connection, select_query);

            if(!query_error){
                printf("query was performed successfully\n");

                res = mysql_store_result(connection);

                //int index=0;
                while((row=mysql_fetch_row(res))){

                    printf("---------------------------------------\nID:%s\nname: %s %s\naddess(parish): %s\n",row[0],row[1],row[2],row[3]);

                    //index++;
                }


            }else{
                printf("there was an error performing the query\n");
            }

        }else{
            printf("connection to database failed with err : %s\n", mysql_error(connection));
        }

    }else{
        printf("connection object problem : %s\n", mysql_error(connection));
    }

    return 0;
}
