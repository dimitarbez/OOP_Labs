#include <iostream>
#include <cstring>
using namespace std;

class Category
{
private:
    char name[20];
public:
    Category(char* name) 
    {
        strncpy(this->name, name, 20);
    }
    Category()
    {
        strncpy(name, "unnamed", 20);
    }
    ~Category() {}
    void print()
    {
        cout << "Category: " << name << endl;;
    }
};

class NewsArticle
{
private:
    Category category;
    char title[30];
public:
    NewsArticle() 
    {
        strncpy(title, "untitled", 30);
    }
    NewsArticle(Category category, char* title = "untitled") 
        :category(category)
    {
        strncpy(this->title, title, 30);
    }

    ~NewsArticle() {}
    void print()
    {
        cout << "Article title: " << title << endl;
        category.print();
    }
};

class FrontPage
{
private:
    NewsArticle article;
    float price;
    int editionNumber;
public:
    FrontPage()
        :price(0), editionNumber(0)
    {
    }
    FrontPage(NewsArticle article, float price = 0, int editionNumber = 0)
        :article(article), price(price), editionNumber(editionNumber)
    {

    }
    ~FrontPage() {}
    void print()
    {
        cout << "Price: " << price << ", " << "Edition number: " << editionNumber << endl;
        article.print();
    }
};

int main()
{
    char categoryName[20];
    char articleTitle[30];
    float price;
    int editionNumber;

    int testCase;
    cin >> testCase;

    if (testCase == 1)
    {
        int iter;
        cin >> iter;
        while (iter > 0)
        {
            cin >> categoryName;
            cin >> articleTitle;
            cin >> price;
            cin >> editionNumber;
            Category category(categoryName);
            NewsArticle article(category, articleTitle);
            FrontPage frontPage(article, price, editionNumber);
            frontPage.print();
            iter--;
        }
    }
    else if (testCase == 2)
    {
        cin >> categoryName;
        cin >> price;
        cin >> editionNumber;
        Category category(categoryName);
        NewsArticle article(category);
        FrontPage frontPage(article, price, editionNumber);
        frontPage.print();
    } // test case 3
    else if (testCase == 3)
    {
        cin >> categoryName;
        cin >> articleTitle;
        cin >> price;
        Category category(categoryName);
        NewsArticle article(category, articleTitle);
        FrontPage frontPage(article, price);
        frontPage.print();
    }
    else
    {
        FrontPage frontPage = FrontPage();
        frontPage.print();
    }
    return 0;
}