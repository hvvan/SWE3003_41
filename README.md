# SWE3003_41
term project for online auction database (Used C, MySQL)



SWE3003_41 Term Project Report
 2018313414
Kim Jihwan
I had a lot of difficulty connecting mysql to ODBC, so the completion of the term project was very low. It's very unfortunate that I had to complete it on a very small scale compared to the ER-model I thought, but I will describe the part I implemented below.
1.	Schema Diagram using E-R model
 
This is the ER schema I implemented. When a user's information is entered, it is managed in the User table, and when a product is entered through the sell option in the main menu, it is checked in the Product schema. And in the case of Administrator, a separate table is configured, and there are no additional functions related to this.
I tried to create a Bid relationship table to control the interaction between users and production, but the implementation failed.

2.	User Manual

a.	Get into the program – Sign Up
  
If you don’t have account, then you should sign up. At the first interface, You should input 2. And then, write your information. Then, your registration is completed.

b.	Log in
 

  Now you can log in. Please type 1 and then log in as your id and password.

c.	Main Menu
 
  Now, you can enjoy my application. At the main menu, I implemented Sell and Search functionalities. And then, the others are not completed. So, if you want to sell, press 1.

d.	Sell
 
As you write your product to sell properly, then our application updates our product data. If this process is completed, then you can automatically back to the main menu.

e.	Search
 
If you press 3 in main menu, you can search the item what you want. Here are the options; (i) search by category, (ii) search by description, (iii) search by seller, and (iv) search by date. Whatever you chose, you can find items if there exists in my application.
If there exists, then my application prints information of search result.
Here is few more examples.

 
Search items by description keyword
 
Search items by seller
 
Search items by date

f.	Log in as administrator
 
Because administrator is important, so you can’t make address of administrator. The only account is stored as data.sql. As I entered administrator account, then I can use the application as normal user.

g.	Other functionalities
Unfortunately, other functionalities did not implemented.
 
  

h.	Quit
If you press Q, then the application is Quit.
 

So, this is my result of term project. Thank you for reading my report.
