class A
{
private:
    float a,b;
public:
    A();
    {
        a = 6.5;
        b = 7;
    }
    ~A();
    {

    }
    operator int()
    {
        float x = (a + b);
        return x;
    }
};
