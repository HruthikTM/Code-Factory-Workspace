#ifndef SHOPKEEPER_H
#define SHOPKEEPER_H

class Shopkeeper
{
private:
    string m_shopkeeperName;
    int m_shopkeeperPhno;
public:
    Shopkeeper();
    ~Shopkeeper();

    void setShopkeeperName(string shopkeeperName);
    string getShopkeeperName();

    void setShopkeeperPhno(int shopkeeperPhno);
    int setShopkeeperPhno();

    void addItem();
    void deleteItem();
    void updateItem();
    bool isItemEmpty();


};

#endif // SHOPKEEPER_H
