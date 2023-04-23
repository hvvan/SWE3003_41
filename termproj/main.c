#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <mysql.h>
#include <time.h>
int login(MYSQL *conn_, char *id)
{

    char PW[40];
    char sqlquery[1000] = {0};
    printf("----(1) Login.   \n");
    printf("---- email: ");
    scanf("%s", id);
    printf("---- password: ");
    scanf("%s", PW);
    // printf("ID: %s\n PW: %s\n", ID, PW);

    sprintf(sqlquery, "select count(User_ID)\
            from User \
            where User_ID = \"%s\" and User_PW = \"%s\"\n",
            id, PW);
    // printf("%s\n", sqlquery);
    if (mysql_query(conn_, sqlquery))
    {
        printf("mysql_query: %s\n", mysql_error(conn_));
        return -1;
    }
    MYSQL_RES *result = mysql_store_result(conn_);
    if (result == NULL)
    {
        printf("mysql_store_result: %s\n, Please Create your ID\n", mysql_error(conn_));
        mysql_free_result(result);
        return -1; /* Create ID */
    }
    else
    {
        MYSQL_ROW row;
        row = mysql_fetch_row(result);
        if (atoi(row[0]) == 0)
        {
            printf("Please Create your ID\n");
            mysql_free_result(result);
            return -1;
        }
        else
        {
            printf("log in completed!\n");
            mysql_free_result(result);
            return 1;
        }
    }
}
int signup(MYSQL *conn_, char *id)
{
    char FNAME[20];
    char LNAME[20];
    // char ID[25];
    char PW[40];
    char sqlquery[1000] = {0};
    printf("----< SignUp >   \n");
    printf("---- first name: ");
    scanf("%s", FNAME);
    printf("---- last name: ");
    scanf("%s", LNAME);
    printf("---- email: ");
    scanf("%s", id);
    printf("---- password: ");
    scanf("%s", PW);

    sprintf(sqlquery, "insert into User values (\'%s\', \'%s\',\'%s\', \'%s\');", FNAME, LNAME, id, PW);
    // printf("%s\n",sqlquery);
    if (mysql_query(conn_, sqlquery))
    {
        printf("mysql_query: %s\n", mysql_error(conn_));
        return -1;
    }
    else
    {
        printf("Registration completed!\n");
        return 1;
    }
}
int login_as_administrator(MYSQL *conn_, char *id)
{
    // char ID[25];
    char PW[40];
    char sqlquery[1000] = {0};
    printf("----(1) Login.   \n");
    printf("---- email: ");

    scanf("%s", id);
    printf("---- password: ");

    scanf("%s", PW);

    // printf("ID: %s\n PW: %s\n", ID, PW);

    sprintf(sqlquery, "select count(Admin_ID) \
            from Administrator \
            where Administrator.Admin_ID = \"%s\" and Administrator.Admin_PW = \"%s\"\n",
            id, PW);
    // printf("%s\n",sqlquery);
    if (mysql_query(conn_, sqlquery))
    {
        printf("mysql_query: %s\n", mysql_error(conn_));
        return -1;
    }
    MYSQL_RES *result = mysql_store_result(conn_);
    if (result == NULL)
    {
        printf("mysql_store_result: %s\n, Log in Failed\n", mysql_error(conn_));
        mysql_free_result(result);
        return -1; /* Create ID */
    }
    else
    {
        MYSQL_ROW row;
        row = mysql_fetch_row(result);
        if (atoi(row[0]) == 0)
        {
            printf("Log in Failed\n");
            mysql_free_result(result);
            return -1;
        }
        else
        {
            printf("Log in completed!\n");
            mysql_free_result(result);
            return 1;
        }
    }
}

char *item_category(int res_num)
{
    static char str1[50] = "Electronics";
    static char str2[50] = "Books";
    static char str3[50] = "Home";
    static char str4[50] = "Clothing";
    static char str5[50] = "Sporting Goods";
    if (res_num == 1)
    {
        return str1;
    }
    if (res_num == 2)
    {
        return str2;
    }
    if (res_num == 3)
    {
        return str3;
    }
    if (res_num == 4)
    {
        return str4;
    }
    if (res_num == 5)
    {
        return str5;
    }
}

char *item_condition(int res_num)
{
    static char str1[50] = "New";
    static char str2[50] = "Like-New";
    static char str3[50] = "Used (Good)";
    static char str4[50] = "Used (Acceptable)";
    if (res_num == 1)
    {
        return str1;
    }
    else if (res_num == 2)
    {
        return str2;
    }
    else if (res_num == 3)
    {
        return str3;
    }
    else
    {
        return str4;
    }
}

int get_Prodid(MYSQL *conn_)
{
    char sqlquery[1000] = {0};
    sprintf(sqlquery, "select count(Prod_id) \
            from Product \n");
    if (mysql_query(conn_, sqlquery))
    {
        printf("mysql_query: %s\n", mysql_error(conn_));
        return -1;
    }
    MYSQL_RES *result = mysql_store_result(conn_);
    if (result == NULL)
    {
        printf("mysql_store_result: %s\n, Please Create your ID\n", mysql_error(conn_));
        mysql_free_result(result);
        return -1; /* Create ID */
    }
    else
    {
        MYSQL_ROW row;
        row = mysql_fetch_row(result);
        if (atoi(row[0]) == 0)
        {
            mysql_free_result(result);
            return 0;
        }
        else
        {
            mysql_free_result(result);
            return (atoi(row[0]));
        }
    }
}

int sell(MYSQL *conn_, char *id)
{
    int category_num;
    int condition_num;
    int check = 0;
    char description[100];
    char buy_it_now[100];
    int buy_price;
    char bid_date[100];
    char category_name[50];
    char condition[50];
    char sqlquery[1000] = {0};
    int ProdId;
    while (1)
    {
        printf("----< Sell item >\n");
        printf("---- select from the following category : \n");
        printf("----(1) Electronics  \n"); // After login, show < Main menu >
        printf("----(2) Books  \n");       // After sign up, show < Login menu >
        printf("----(3) Home \n");         // After sign up, show < Login menu >
        printf("----(4) Clothing \n");
        printf("----(5) Sporting Goods \n");
        scanf("%d", &category_num);
        if (category_num < 1 && category_num > 5)
        {
            continue;
        }
        else
        {
            break;
        }
    }
    strcpy(category_name, item_category(category_num));
    while (1)
    {
        printf("---- condition : \n");
        printf("----(1) New  \n");        // After login, show < Main menu >
        printf("----(2) Like-New  \n");   // After sign up, show < Login menu >
        printf("----(3) Used (Good) \n"); // After sign up, show < Login menu >
        printf("----(4) Used (Acceptable) \n");
        scanf("%d", &condition_num);
        if (condition_num < 1 && condition_num > 5)
        {
            continue;
        }
        else
        {
            break;
        }
    }
    strcpy(condition, item_condition(condition_num));
    printf("----description: ");
    getchar();
    scanf("%[^\n]s", description);
    while (1)
    {
        printf("----buy-it-now-price: ");
        memset(buy_it_now, 0, sizeof(buy_it_now));
        scanf("%s", buy_it_now);
        for (int i = 0; i < strlen(buy_it_now); i++)
        {
            if (!isdigit(buy_it_now[i]))
            {
                check = 0;
                break;
            }
            else if (isdigit(buy_it_now[i]) && i == strlen(buy_it_now) - 1)
            {
                check = 1;
            }
        }
        if (check == 0)
            continue;
        else
            break;
    }
    buy_price = atoi(buy_it_now);
    printf("----bid ending date(YYYY-MM-DD): ");
    scanf("%s", bid_date);
    ProdId = get_Prodid(conn_);
    sprintf(sqlquery, "insert into Product values (%d,current_timestamp,\'%s\', \'%s\',\'%s\', \'%s\',%d,\'%s\');", ProdId + 1, category_name, condition, description, bid_date, buy_price, id);
    if (mysql_query(conn_, sqlquery))
    {
        printf("mysql_query: %s\n", mysql_error(conn_));
        return -1;
    }
    else
    {
        printf("Your Product is on Bidding!\n");
        return 1;
    }
}

int search(MYSQL *conn_, char *id)
{
    int category_num;
    while (1)
    {
        char sqlquery[1000] = {0};
        printf("----< Search item >\n");
        printf("----(1) Search items by category  \n");
        printf("----(2) Search items by description keyword  \n");
        printf("----(3) Search items by seller \n");
        printf("----(4) Search items by date posted \n");
        printf("----(5) Go Back \n");
        printf("----(6) Quit \n");
        scanf("%d", &category_num);
        if (category_num < 1 && category_num > 6)
        {
            continue;
        }
        else if (category_num == 6)
        {
            return 1;
        }
        else if (category_num == 1)
        {
            int item_num;
            char category_query[50] = {0};
            while (1)
            {
                printf("----< Search items by category >\n");
                printf("----(1) Electronics  \n");
                printf("----(2) Books  \n");
                printf("----(3) Home \n");
                printf("----(4) Clothing \n");
                printf("----(5) Sporting Goods \n");

                scanf("%d", &item_num);
                if (item_num >= 1 && item_num <= 5)
                    break;
                printf("Please Write Valid Input: (1-5)\n");
            }
            if (item_num == 1)
            {
                sprintf(category_query, "Electronics");
            }
            else if (item_num == 2)
            {
                sprintf(category_query, "Books");
            }
            else if (item_num == 3)
            {
                sprintf(category_query, "Home");
            }
            else if (item_num == 4)
            {
                sprintf(category_query, "Clothing");
            }
            else if (item_num == 5)
            {
                sprintf(category_query, "Sporting Goods");
            }
            sprintf(sqlquery, "select Prod_Description, Prod_Date, Prod_end_date\
            from Product \
            where Prod_Category = \"%s\" \n",
                    category_query);
        }
        else if (category_num == 2)
        {
            char keyword[50];
            printf("----< Search items by description keyword >\n");
            printf("----Search keyword: ");
            scanf("%s", keyword);
            sprintf(sqlquery, "select Prod_Description, Prod_Date, Prod_end_date\
            from Product \
            where Prod_Description like \"%%%s%%\" \n",
                    keyword);
        }
        else if (category_num == 3)
        {
            char Seller[50];
            printf("----< Search items by seller >\n");
            printf("----Search Seller: ");
            scanf("%s", Seller);
            sprintf(sqlquery, "select Product.Prod_Description, Product.Prod_Date, Product.Prod_end_date\
            from Product, User \
            where Product.Seller_ID = User.User_ID and (User.User_FName = \"%s\" or User.User_FName = \"%s\")\n",
                    Seller, Seller);
        }
        else if (category_num == 4)
        {
            char Date[50];
            printf("----< Search items by date posted >\n");
            printf("----Search Date (YYYY-MM-DD): ");
            scanf("%s", Date);
            sprintf(sqlquery, "select Product.Prod_Description, Product.Prod_Date, Product.Prod_end_date\
            from Product \
            where Product.Prod_Date= \"%s\" \n",
                    Date);
        }
        else if (category_num == 5)
        {
            printf("Go back\n");
            return 0;
        }
        if (mysql_query(conn_, sqlquery))
        {
            printf("mysql_query: %s\n", mysql_error(conn_));
            return -1;
        }
        MYSQL_RES *result = mysql_store_result(conn_);
        if (result == NULL)
        {
            printf("mysql_store_result: %s\n, Please Create your ID\n", mysql_error(conn_));
            mysql_free_result(result);
            return -1; /* Create ID */
        }
        else
        {
            int num_fields = mysql_num_fields (result);
            MYSQL_ROW row;
            MYSQL_FIELD *field;
            while ((row = mysql_fetch_row(result)))
            {
                for (int i = 0; i < num_fields; i++)
                {
                    if (i == 0)
                    {
                        while (field = mysql_fetch_field(result))
                        {
                            printf("%s ", field->name);
                        }
                        printf("\n ");
                    }
                    printf("%s ", row[i] ? row[i] : "NULL");
                }
            }
            printf("\n ");
        }
    }
}
int main(int argc, char *argv[])
{
    char user_ID[25];
    char admin_ID[25];
    MYSQL *conn = mysql_init(NULL);
    if (conn == NULL)
    {
        printf("mysql_init: %s\n", mysql_error(conn));
        exit(1);
    }

    if (mysql_real_connect(conn, "localhost", "2018313414", "thomaskk0309", "db2018313414", 0, NULL, 0) == NULL)
    {
        printf("mysql_real_connect: %s\n", mysql_error(conn));
        mysql_close(conn);
        exit(1);
    }
    int id_response;
    int signup_response;
    int admin_response;
    int main_menu_mode; /* 1: normal user, 2: admin. */
    /* get user options */
    int user_input = 0;
    int return_code = 0;

    do
    {
        printf("----< Login menu >\n");
        printf("----(1) Login.   \n");              // After login, show < Main menu >
        printf("----(2) Sign up  \n");              // After sign up, show < Login menu >
        printf("----(3) Login as Administrator\n"); // After sign up, show < Login menu >
        printf("----(4) Quit \n");                  // Exit the program
        user_input = 0;
        printf("    Your choice: ");
        scanf("%d", &user_input);

        if (user_input == 1)
        {
            // printf("login\n");
            memset(user_ID, 0, sizeof(user_ID));
            id_response = login(conn, user_ID);
            if (id_response < 0)
            {
                printf("You wrote invalid ID and PW.\n");
                continue;
            }
            else
            {
                printf("Main Menu\n");
                break;
            }
        }
        else if (user_input == 2)
        {
            printf("signup()\n");
            memset(user_ID, 0, sizeof(user_ID));
            signup_response = signup(conn, user_ID);
            if (signup_response < 0)
            {
                printf("Sign up Failed.\n");
                continue;
            }
            else
                continue;
        }
        else if (user_input == 3)
        {
            printf("login as administrator()\n");
            memset(admin_ID, 0, sizeof(admin_ID));
            admin_response = login_as_administrator(conn, admin_ID);
            if (admin_response < 0)
            {
                printf("You wrote invalid ID and PW.\n");
                continue;
            }
            else
            {
                printf("Main Menu\n");
                break;
            }
        }
        else if (user_input == 4)
        {
            printf("quit\n");

            // mysql_free_result(result);
            mysql_close(conn);
            return 0;
        }
        else
        {
            printf("Please write valid number. (1-4)\n");
        }
    } while (1);
    getchar();
    char main_user_input;
    int ret_val;
    do
    {
        printf("----< Main menu >\n");
        printf("----(1) Sell item   \n");                            // sell item
        printf("----(2) Status of Your Item Listed on Auction  \n"); // find status of item
        printf("----(3) Search item \n");                            // After sign up, show < Login menu >
        printf("----(4) Check Status of your Bid \n");               // After sign up, show < Login menu >
        printf("----(5) Check your Account \n");                     // After sign up, show < Login menu >
        printf("----(Q) Quit \n");                                   // Exit the program
        printf("    Your choice: ");

        scanf("%c", &main_user_input);
        rewind(stdin);
        if (main_user_input == '1')
        {
            ret_val = sell(conn, user_ID);
            if (ret_val == 1)
                continue;
            else
            {
                printf("Selling error\n");
                continue;
            }
        }
        else if (main_user_input == '2')
        {
            printf("----(2) Status of Your Item Listed on Auction  \n"); 
            continue;
        }
        else if (main_user_input == '3')
        {
            ret_val = search(conn, user_ID);
            if (ret_val == 1)
                break;
            else
                continue;
        }
        else if (main_user_input == '4')
        {
            printf("----(4) Check Status of your Bid \n");               // After sign up, show < Login menu >
            continue;
        }
        else if (main_user_input == '5')
        {
            printf("----(5) Check your Account \n");                     // After sign up, show < Login menu >
            continue;
        }
        else if (main_user_input == 'Q')
        {
            return_code = 1;
            break;
        }
        else
        {
            printf("Please write invalid response.\n");
            continue;
        }

    } while (1);

    mysql_close(conn);

    return 1;
}
