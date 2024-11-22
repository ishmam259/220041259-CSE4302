#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;


class selleractions {
public:
virtual void ServeIceCream() = 0;
virtual void promoteDeal() = 0;
virtual void SpecialOffer() = 0;
virtual void displayStats() const = 0;
virtual ~selleractions() {}

};


class BaseSeller : public selleractions 
{
protected:
string name;
int stock;
int sales;
int salesCount; 
bool SpecialOfferReady;

public:
    BaseSeller(string sellerName, int initialStock) 
    : name(sellerName), stock(initialStock), sales(0), salesCount(0), SpecialOfferReady(false) 
    {}


    void ServeIceCream()                        //override 
    {
        if (stock > 0) 
        {
            int saleIncrease = rand() % 23 + 8; 
            sales += saleIncrease;

            salesCount++;
            stock--;

            cout<<name << " served! Sales increased by " << saleIncrease << ". Total Sales: " << sales << ", Stock: " << stock << endl;


            if (salesCount % 3 == 0) 
            {
                SpecialOfferReady = true;
                cout<< name << "'s special offer is now ready!" << endl;
            }
        } 
        else 
        {
            cout<<name<< "is out of stock!" << endl;
        }
    }

    void promoteDeal()                                //override 
    {
        cout << name << " promoted a deal! Sales doubled for two turns!" << endl;
        sales *= 2;
    }

    virtual void SpecialOffer()                             //override 
    {
        cout << name << " has no unique special offer!" << endl;
    }

    void displayStats() const                                   //override 
    {
        cout << "Seller: " << name <<"\n"
             << ", Stock: " << stock <<"\n"
             << ", Sales: " << sales <<"\n"
             << ", Special Offer Ready: " << (SpecialOfferReady ? "Yes" : "No") << endl;
    }

    bool isSpecialOfferReady() const 
    {
        return SpecialOfferReady;
    }

    void resetSpecialOfferReady() 
    {
        SpecialOfferReady = false;
    }

    int getSales() const 
    {
        return sales;
    }

    int getStock() const 
    {
        return stock;
    }

    void increaseStock(int amount) 
    {
        stock += amount;
    }
};



class ConeMaster : public BaseSeller 
{
public:

    ConeMaster() 
    : BaseSeller("Cone Master", 20) 
    {}

    void ServeIceCream()                        //override 
    {
        if (stock <= 0) 
        {
            cout << name << " is out of stock!" << endl;
            return;
        }
        
        int scoopsStacked = rand() % 4+ 1;
        if (scoopsStacked > 1)
        { 

            int successRate = 100 - (scoopsStacked * 10);
            int challengeResult = rand() % 100;

            cout<<name<< " attempts Cone Stack Challenge with " << scoopsStacked << " scoops. ";
            if (challengeResult < successRate) 
            {
                int saleIncrease = scoopsStacked * (rand() % 23 + 8);
                sales += saleIncrease;
                stock--;
                salesCount++;
                cout << "Success! Sales increased by " << saleIncrease<< ". Total Sales: " << sales << ", Stock: " << stock << endl;
            } 
        else if (scoopsStacked == 1)
        {
            BaseSeller::ServeIceCream();
        }
        else 
        {
                stock--;
                cout << "The stack toppled! No sales recorded. Stock remaining: " << stock << endl;
        }
        } 

        if (salesCount % 3 == 0) 
        {
            SpecialOfferReady = true;
        }
    }

    void SpecialOffer()                            //override 
    {
        if (SpecialOfferReady) 
        {
            cout << name <<" uses special offer: Serving three cones at once!"<< endl;
            for (int i = 0; i < 3; i++) 
            {
                ServeIceCream();
            }
            SpecialOfferReady = false;
        } 
        else 
        {
            cout << name << "'s special offer is not ready yet!" << endl;
        }
    }
};




class SundaeWizard : public BaseSeller 
{
public:
    SundaeWizard() 
    : BaseSeller("Sundae Wizard", 15) 
    {}

    void ServeIceCream()                           //override 
    {
        if (stock <= 0) {
            cout << name << " is out of stock!" << endl;
            return;
        }

        int layers = rand() % 5 + 1;
        if (layers > 1 ) 
        {  
            int saleIncrease = layers * (rand() % 23 + 8);
            sales += saleIncrease;
            stock--;
            salesCount++;
            cout << name << " served a layered sundae with " << layers 
                 << " layers! Sales increased by " << saleIncrease 
                 << ". Total Sales: " << sales << ", Stock: " << stock << endl;
        } 
        else 
        {
            BaseSeller::ServeIceCream();
        }

        if (salesCount % 3 == 0) 
        {
            SpecialOfferReady = true;
        }
    }

    void SpecialOffer()                                            //override 
    {
        if (SpecialOfferReady) 
        {
            promoteDeal();
            SpecialOfferReady = false;
        } 
        else 
        {
            cout << name << "'s special offer is not ready yet!" << endl;
        }
    }
};



class IceCreamTruckDriver : public BaseSeller 
{
public:
    IceCreamTruckDriver() 
    : BaseSeller("Ice Cream Truck Driver", 30) 
    {}

    void SpecialOffer()                                        //override 
    {
        if (SpecialOfferReady) 
        {
            increaseStock(10);
            cout << name << " restocked 10 units of ice cream!" << endl;
            SpecialOfferReady = false;
        } 
        else 
        {
            cout<<name<<"'s special offer is not ready yet!" << endl;
        }
    }
};


class CustomerRush 
{
int patience;
public:
CustomerRush(int initialPatience) 
: patience(initialPatience) 
{}

    void decreasePatience() 
    {
        int patienceLoss = rand() % 50 + 20; 
        patience -= patienceLoss;
    }

    int getPatience() const 
    {
        return patience;
    }

    bool isSatisfied(int totalSales) const 
    {
        return totalSales >= 300;
    }

    bool isOutOfPatience() const 
    {
        return patience <= 0;
    }
};


class Start
{
    BaseSeller* sellers[3];
    CustomerRush customerRush;

public:
    Start() 
    : customerRush(200) 
    {
    sellers[0] = new ConeMaster();
    sellers[1] = new SundaeWizard();
    sellers[2] = new IceCreamTruckDriver();
    }

    ~Start() 
    {
        for (int i = 0; i < 3; i++) 
        {
            delete sellers[i];
        }
    }

    void startPlay() 
    {
        int turn = 1;
        int totalSales = 0;

        while( turn <= 10 && !customerRush.isOutOfPatience() ) 
        {
            cout <<"Turn"<<turn<< ":\n";

            for (int i = 0; i < 3; i++) 
            {
                sellers[i]->ServeIceCream();
                totalSales += sellers[i]->getSales();
                if (sellers[i]->isSpecialOfferReady()) 
                {
                    sellers[i]->SpecialOffer();
                }
            }

            cout<<"Collective totalSales:"<<totalSales<<endl;

            if( customerRush.isSatisfied(totalSales) ) 
            {
                cout <<"Customer Rush satisfied! Sellers win!\n";
                return;
            }

            customerRush.decreasePatience();
            cout << "Customer patience left: " << customerRush.getPatience() << "\n";
            turn++;
        }

        cout<<"Sellers lose! Either stock ran out, sales goal wasn't reached, or customer lost patience.\n";
    }
};

int main() {
    srand(time(0)); 

    cout << "Game begins! Sellers vs. Customer Rush\n";
    Start game;
    game.startPlay();
}