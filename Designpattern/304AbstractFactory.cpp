// cppcheck-suppress-file unusedFunction
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <functional>

// 船体
class AbstractShipDody
{
public:
    virtual std::string getShipBody() = 0;
    virtual ~AbstractShipDody() {}
};

// 木头船体
class WoodShipBody : public AbstractShipDody
{
public:
    std::string getShipBody() override
    {
        std::string str("船体类型<木头船体>已创建...");
        return str;
    }
};

// 钢铁船体
class IronShipBody : public AbstractShipDody
{
public:
    std::string getShipBody() override
    {
        std::string str("船体类型<钢铁船体>已创建...");
        return str;
    }
};

// 合金船体
class MetalShipBody : public AbstractShipDody
{
public:
    std::string getShipBody() override
    {
        std::string str("船体类型<合金船体>已创建...");
        return str;
    }
};

// 驱动
class AbstractDrive
{
public:
    virtual std::string getDrive() = 0;
    virtual ~AbstractDrive() {}
};

// 人力驱动
class HumanDrive :public AbstractDrive
{
public: 
    std::string getDrive() override
    {
        std::string str("人力驱动已配置...");
        return str;
    }
};

// 内燃驱动
class DieselDrive : public AbstractDrive
{
public: 
    std::string getDrive() override
    {
        std::string str("内燃驱动已配置...");
        return str;
    }
};

// 核能驱动
class NuclearDrive : public AbstractDrive
{
public: 
    std::string getDrive() override
    {
        std::string str("核能驱动已配置...");
        return str;
    }
};

// 武器
class AbstractWeapon
{
public:
    virtual std::string getWeapon() = 0;
    virtual ~AbstractWeapon() {}
};
// 枪
class GunWeapon: public AbstractWeapon
{
public: 
    std::string getWeapon() override
    {
        std::string str("武器<枪>已配置...");
        return str;
    }
};

// 佳能炮
class CannonWeapon: public AbstractWeapon
{
public: 
    std::string getWeapon() override
    {
        std::string str("武器<佳能炮>已配置...");
        return str;
    }
};

// 激光
class LaserWeapon: public AbstractWeapon
{
public: 
    std::string getWeapon() override
    {
        std::string str("武器<激光>已配置...");
        return str;
    }
};

class Ship
{
public:
    Ship(AbstractShipDody *body,
        AbstractDrive *drive,
        AbstractWeapon *weapon)
        :m_body(body)
        ,m_drive(drive)
        ,m_weapon(weapon) {}
    
    ~Ship()
    {
        delete m_body;
        delete m_drive;
        delete m_weapon;
    }
    std::string getProperty()
    {
        std::string info;
        info = m_body->getShipBody() + m_drive->getDrive() + m_weapon->getWeapon();
        return info;
    }

private:
    // 船的组成部分
    AbstractShipDody *m_body;
    AbstractDrive *m_drive;
    AbstractWeapon *m_weapon;
};

// 抽象工厂
class AbstractFactory
{
public:
    virtual Ship *CreateShip() = 0;
    virtual ~AbstractFactory() {}
};


// 基础船-工厂
class BasicShipFactory:public AbstractFactory
{
public:
    Ship *CreateShip() override
    {
        Ship* ship = new Ship(new WoodShipBody, new HumanDrive, new GunWeapon);
        std::cout << "<基础类型的海贼船>已建造完毕！！！" << std::endl;
        return ship;
    }
};

// 标准船-工厂
class StandardShipFactory:public AbstractFactory
{
public:
    Ship *CreateShip() override
    {
        Ship *ship =new Ship(new IronShipBody, new DieselDrive, new CannonWeapon);
        std::cout << "<标准类型的海贼船>已建造完毕！！！" << std::endl;
        return ship;
    }
};

// 豪华船-工厂
class UltimaShipFactory:public AbstractFactory
{
public:
    Ship *CreateShip() override
    {
        Ship *ship =new Ship(new MetalShipBody, new NuclearDrive, new LaserWeapon);
        std::cout << "<旗舰类型的海贼船>已建造完毕！！！" << std::endl;
        return ship;
    }
};


int main()
{
    // 创建基础工厂
    AbstractFactory *b_factory = new BasicShipFactory;
    Ship* b_ship = b_factory->CreateShip();
    std::cout << b_ship->getProperty() << std::endl;

    delete b_factory;
    delete b_ship;
    return 0;
}