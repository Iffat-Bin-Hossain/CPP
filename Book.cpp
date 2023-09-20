/************Topics of Practice*************************/
/* => Dynamic Allocation of objects         		   */
/* => Constructor overloading		        		   */
/* => Copy constructor				        		   */
/* => Passing and returning objects from functions     */
/*******************************************************/

#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

class Book
{
    int isbn;
    char* title;
    double price;
public:
    //Constructor functions
    Book() //default constructor
    {
        //cout<<"In the default constructor of Book"<<endl;
        //Write your code here
        isbn=-3;
        price=0;
        title=new char[9];//Length of "No Title" including NULL Character=9
        if(title==NULL)
        {
            cout<<"Memory Allocation Error"<<endl;
        }
        strcpy(title,"No Title");
    }

    Book(int isbn,const char* title,int price) //constructor with arguments
    {
        //cout<<"In the parameterized constructor of Book "<<isbn<<endl;
        //Write your code here
        this->isbn=isbn;
        this->title=new char[strlen(title)+1];
        if(this->title==NULL)
        {
            cout<<"Memory Allocation Error"<<endl;
        }
        strcpy(this->title,title);
        this->price=price;


    }
    Book(const Book& book) //Copy constructor
    {
        //cout<<"In the copy constructor of Book "<<isbn<<endl;
        //Write your code here
        isbn=book.isbn;
        title=new char[strlen(book.title)+1];
        if(title==NULL)
        {
            cout<<"Memory Allocation Error"<<endl;
        }
        strcpy(title,book.title);
        price=book.price;

    }

    //Destructor function
    ~Book()
    {
        //cout<<"In the destructor of Book "<<isbn<<endl;
        //Write your code here
        delete[]title;
        //cout<<"Freeing Book "<<endl;
    }

    //Write the setter functions here
    void Set_isbn(int I)
    {
        //cout<<"Setting the value of ISBN"<<endl;
        isbn=I;
    }
    void Set_title(const char *T)
    {
        //cout<<"Setting the Title"<<endl;
        title=new char[strlen(T)+1];
        if(title==NULL)
        {
            cout<<"Memory Allocation Error"<<endl;
        }
        strcpy(title,T);


    }
    void Set_price(double P)
    {
        //cout<<"Setting the value of Price"<<endl;
        price=P;
    }


    //Write the getter functions here
    int Get_isbn()
    {
        //Returning the value of isbn
        return isbn;
    }
    double Get_price()
    {
        //Returning the value of price
        return price;
    }
    char* Get_title()
    {
        //Returning the value of isbn
        return title;
    }

    //Service functions
    void print()
    {
        //Write your code here
        //cout<<"Printing the value of members"<<endl;
        //cout<<"title:"<<title<<",isbn:"<<isbn<<",price:"<<price<<endl;
        cout<<"ISBN: "<<isbn<<", Title: "<<title<<", Price: "<<price<<endl;
    }

    int isTheSameBook(Book b)
    {
        //Write your code here
        //Checking if two books are same
        if(isbn==b.isbn) return 1;
        else return 0;
    }

    Book generateNewEdition(int isbn,int price)
    {
        //Write your code here
        //A new edition of current book
        Book Temporary;
        Temporary.isbn=isbn;
        Temporary.price=price;
        Temporary.title=new char[strlen(title)+1];
        if(Temporary.title==NULL)
        {
            cout<<"Memory Allocation Error"<<endl;
        }
        strcpy(Temporary.title,title);

        return Temporary;

    }
    Book operator=(Book &b)//Operator Overloading for = operator
    {
        title=new char[strlen(b.title)+1];
        strcpy(title,b.title);
        isbn=b.isbn;
        price=b.price;

        return *this;
    }

};


/*int main()
{
    //To do: Create a book object named b1 with the default constructor
    Book b1;

    //To do: Set the properties of b1 as follows: isbn=101, title="Teach yourself C++", price=230
    b1.Set_isbn(101);
    b1.Set_title("Teach yourself C++");
    b1.Set_price(230);

    //To do: Print the details of b1
    b1.print();

    //To do: Create a book object named b2 with values initialized as- isbn=102, title="Teach Yourself Java", price=235
    Book b2(102,"Teach Yourself Java",235);

    //To do: Crate a book object b3 and initialize with b2
    Book b3(b2);

    //To do: Check if b2 and b3 represent the same book. Print "Yes" or "No" based on the check result.
    int R=b3.isTheSameBook(b2);
    if(R==1)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }

    //To do: Change the title of b3 to "Teach Yourself Java in Thirty Days"
    b3.Set_title("Teach Yourself Java in Thirty Days");

    //To do: Change the isbn of b3 to 103
    b3.Set_isbn(103);

    //To do: Print the details of book b2 and b3
    b2.print();
    b3.print();

    //To do: Create a book b4 as a new edition of b3. Set the isbn and price of the new edition to 104 and 600, respectively
    Book b4=b3.generateNewEdition(104,600);

    //To do: Print the details of b4
    b4.print();

    //To do: Create a Book pointer named bp1
    Book *bp1;

    //To do: Allocate a Book object to bp1 initialized as- isbn=104, title="C++ For Dummies", price=400
    bp1=new Book(104,"C++ For Dummies",400);
    if(bp1==NULL)
    {
        cout<<"Memory Allocation Error"<<endl;
    }


    //To do: Print the details of the book pointed by bp1
    bp1->print();

    //To do: Free the memory allocated to bp1
    free(bp1);

    //To do: Create a Book pointer named bl1 and allocate three book objects to it without any initialization
    Book *bl1;
    bl1=new Book[3];
    if(bl1==NULL)
    {
        cout<<"Memory Allocation Error"<<endl;
    }

    //To do: Set the properties of the three book objects pointed to by bl1 as follows:
    // <isbn=201, title=Compilers, price=340>
    bl1[0].Set_isbn(201);
    bl1[0].Set_title("Compilers");
    bl1[0].Set_price(340);
    // <isbn=202, title=Operating Systems, price=450>,
    bl1[1].Set_isbn(202);
    bl1[1].Set_title("Operating Systems");
    bl1[1].Set_price(450);
    // <isbn=203, title=Data Communications, price=600>
    bl1[2].Set_isbn(203);
    bl1[2].Set_title("Data Communications");
    bl1[2].Set_price(600);

    //To do: Print the details of all the three books pointed to by bl1
    int i=0;
    while(i<3)
    {
        bl1[i].print();
        i++;
    }

    //To do: Free the memory allocated to bl1
    delete[] bl1;
}*/
