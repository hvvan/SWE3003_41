# SWE3003_41
term project for online auction database (Used C, MySQL)



SWE3003_41 Term Project Report
 2018313414
Kim Jihwan
I had a lot of difficulty connecting mysql to ODBC, so the completion of the term project was very low. It's very unfortunate that I had to complete it on a very small scale compared to the ER-model I thought, but I will describe the part I implemented below.
1.	Schema Diagram using E-R model

![A](https://user-images.githubusercontent.com/90609711/233830907-de7f599a-1152-4a03-b5b8-c5dfb42b61d8.png)

This is the ER schema I implemented. When a user's information is entered, it is managed in the User table, and when a product is entered through the sell option in the main menu, it is checked in the Product schema. And in the case of Administrator, a separate table is configured, and there are no additional functions related to this.
I tried to create a Bid relationship table to control the interaction between users and production, but the implementation failed.

2.	User Manual

a.	Get into the program – Sign Up

 ![B](https://user-images.githubusercontent.com/90609711/233830886-26af6fef-39a8-42b5-8aab-2c1ee779a9f6.png)
![C](https://user-images.githubusercontent.com/90609711/233830889-a4221d37-f703-4ea8-acac-2ba457393f2f.png)

If you don’t have account, then you should sign up. At the first interface, You should input 2. And then, write your information. Then, your registration is completed.

b.	Log in
 
 ![D](https://user-images.githubusercontent.com/90609711/233830890-3dc1348a-5b3f-419e-8207-a199de8f0cf4.png)



  Now you can log in. Please type 1 and then log in as your id and password.

c.	Main Menu

![E](https://user-images.githubusercontent.com/90609711/233830892-ed690b2d-37cc-4151-adf1-7a54cc0bf15a.png)

 
  Now, you can enjoy my application. At the main menu, I implemented Sell and Search functionalities. And then, the others are not completed. So, if you want to sell, press 1.

d.	Sell

![F](https://user-images.githubusercontent.com/90609711/233830895-565f337c-d323-4b3c-add1-cb137379701d.png)


As you write your product to sell properly, then our application updates our product data. If this process is completed, then you can automatically back to the main menu.

e.	Search

![G](https://user-images.githubusercontent.com/90609711/233830896-c4bbbc3c-a75d-436b-8ae2-00ba05c4cbdc.png)

 
If you press 3 in main menu, you can search the item what you want. Here are the options; (i) search by category, (ii) search by description, (iii) search by seller, and (iv) search by date. Whatever you chose, you can find items if there exists in my application.
If there exists, then my application prints information of search result.
Here is few more examples.

 
Search items by description keyword
 
![H](https://user-images.githubusercontent.com/90609711/233830897-28ce8771-ced1-4b0e-b893-5a921a2f7c42.png)

Search items by seller
 
![I](https://user-images.githubusercontent.com/90609711/233830899-24912bb2-22fd-4d1b-8e4a-07fd1ad9147b.png)
 
Search items by date

![J](https://user-images.githubusercontent.com/90609711/233830900-392523f8-45fd-4615-bb25-044c762c0b8a.png)

f.	Log in as administrator
 
![K](https://user-images.githubusercontent.com/90609711/233830901-6e03ce44-be7b-4a2e-b7e3-352bb0c55c40.png)

 
Because administrator is important, so you can’t make address of administrator. The only account is stored as data.sql. As I entered administrator account, then I can use the application as normal user.

g.	Other functionalities

![L](https://user-images.githubusercontent.com/90609711/233830902-7b1273ab-59bf-4cbb-a338-1990b45fec65.png)
![M](https://user-images.githubusercontent.com/90609711/233830903-8128052b-be17-4d62-9b53-20a75897f651.png)
![N](https://user-images.githubusercontent.com/90609711/233830905-892d0c67-3ee5-4466-abae-797dded227d6.png)

Unfortunately, other functionalities did not implemented.
 
  

h.	Quit

![O](https://user-images.githubusercontent.com/90609711/233830906-7f53ffbc-6415-4599-af46-0562f8e45aee.png) 


If you press Q, then the application is Quit.
 

So, this is my result of term project. Thank you for reading my report.
