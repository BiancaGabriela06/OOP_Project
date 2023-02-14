#include <iostream>
#include <vector>
#include <typeinfo>

using namespace std;

/**** ABSTRACT OBJECT FACTORY  ***/
/* Clasa mea de baza (care e si clasa abstracta) este Accesory. Definim 4 tipuri de clase:
 * Ochelari de Femei, Ochelari de Barbati, Esarfa de Femei, Esarfa de Barbati.
 * corelez Ochelari de Femei cu Esarfa de Femei  -> Accesorii de Femei
 *                 si
 *   Ochelari de Barbati cu Esarfa de Barbati   -> Accesorii de Barbati
 * */

/// got abstract class

class Accessory {
public:
    virtual void output() = 0;
    virtual void input() = 0;
};


///PRODUSE DE TIP A
class GlassesLadies: public Accessory{
    string colour, shape;

public:
    void output() {
        cout <<"Ladies's Glasses: "<< colour << " "<< shape <<endl;
    }

    void input(){
        cout << "Insert color and shape for ladies's glasses: " << endl;
        cin >> colour >> shape;
    }

    GlassesLadies(){};
    GlassesLadies(const string &colour, const string &shape);

    virtual ~GlassesLadies();

    friend istream& operator>>(istream& in, GlassesLadies&ob);
    friend ostream& operator<<(ostream& out, GlassesLadies&ob);

    const string &getColour() const {
        return colour;
    }

    void setColour(const string &colour) {
        GlassesLadies::colour = colour;
    }

    const string &getShape() const {
        return shape;
    }

    void setShape(const string &shape) {
        GlassesLadies::shape = shape;
    }

};

istream& operator>>(istream& in, GlassesLadies& ob){

    in >> ob.colour >> ob.shape;
    return in;
}

ostream& operator<<(ostream& out, GlassesLadies& ob){
    out<< ob.colour <<" "<< ob.shape;
    return out;
}

GlassesLadies::GlassesLadies(const string &colour, const string &shape) : colour(colour), shape(shape) {}

GlassesLadies::~GlassesLadies() {}

class GlassesMen: public Accessory{
    string colour, shape;

public:
    GlassesMen(){};
    GlassesMen(const string &colour, const string &shape);

    virtual ~GlassesMen();

    void output() {
        cout <<"Men's Glasses: " << colour <<" " << shape <<endl;
    }

    void input(){
        cout << "Insert color and shape for men's glasses: "  << endl;
        cin >> colour >> shape;
    }

    friend istream& operator>>(istream& in, GlassesMen&ob);
    friend ostream& operator<<(ostream& out, GlassesMen&ob);

    const string &getColour() const;

    void setColour(const string &colour);

    const string &getShape() const;

    void setShape(const string &shape);

};

istream& operator>>(istream& in, GlassesMen& ob){
    in >> ob.colour >> ob.shape;
    return in;
}

ostream& operator<<(ostream& out, GlassesMen& ob){
    out<< ob.colour <<" "<< ob.shape;
    return out;
}

const string &GlassesMen::getColour() const {
    return colour;
}

void GlassesMen::setColour(const string &colour) {
    GlassesMen::colour = colour;
}

const string &GlassesMen::getShape() const {
    return shape;
}

void GlassesMen::setShape(const string &shape) {
    GlassesMen::shape = shape;
}

GlassesMen::GlassesMen(const string &colour, const string &shape) : colour(colour), shape(shape) {}

GlassesMen::~GlassesMen() {}

/// PRODUS TIP B
class ScarfLadies: public Accessory{
    string colour, material;
public:
    virtual ~ScarfLadies();
    ScarfLadies(){};
    ScarfLadies(const string &colour, const string &material);

    void output() {
        cout <<"Ladies's Scarfs: "<< colour<< " "<< material <<endl;
    }

    void input(){
        cout <<"Insert colour and material for ladies's scarf:" << endl;
        cin >> colour >> material;
    }

    friend istream& operator>>(istream& in, ScarfLadies&ob);
    friend ostream& operator<<(ostream& out, ScarfLadies&ob);

    const string &getColour() const;

    void setColour(const string &colour);

    const string &getMaterial() const;

    void setMaterial(const string &material);
};

istream& operator>>(istream& in, ScarfLadies& ob){
    in >> ob.colour >> ob.material;
    return in;
}

ostream& operator<<(ostream& out, ScarfLadies& ob){
    out<< ob.colour <<" "<< ob.material;
    return out;
}

const string &ScarfLadies::getColour() const {
    return colour;
}

void ScarfLadies::setColour(const string &colour) {
    ScarfLadies::colour = colour;
}

const string &ScarfLadies::getMaterial() const {
    return material;
}

void ScarfLadies::setMaterial(const string &material) {
    ScarfLadies::material = material;
    ScarfLadies::material = material;
}

ScarfLadies::~ScarfLadies() {}

ScarfLadies::ScarfLadies(const string &culoare, const string &material) : colour(colour), material(material) {}

class ScarfMen: public Accessory{
    string colour, material;
public:
    virtual ~ScarfMen();
    ScarfMen(){};
    ScarfMen(const string &colour, const string &material);

    void output() {
        cout <<"Men's Scarfs " << colour <<" "<< material<<endl;
    }

    void input(){
        cout <<"Insert colour and material for men's scarf: " << endl;
        cin >> colour >> material;
    }
    friend istream& operator>>(istream& in, ScarfMen&ob);
    friend ostream& operator<<(ostream& out, ScarfMen&ob);
};

istream& operator>>(istream& in, ScarfMen& ob){
    in >> ob.colour >> ob.material;
    return in;
}

ostream& operator<<(ostream& out, ScarfMen& ob){
    out<< ob.colour <<" "<< ob.material;
    return out;
}

ScarfMen::~ScarfMen() {}

ScarfMen::ScarfMen(const string &colour, const string &material) : colour(colour), material(material) {}

class Factory{

public:
    virtual Accessory* create_accessory_glasses() = 0;
    virtual Accessory* create_accessory_scarf() = 0;
};

class Accessories_Ladies: public Factory{
public:
    Accessory* create_accessory_glasses() {
        Accessory* p = new GlassesLadies();
        p-> input();
        return p;
    }

    Accessory* create_accessory_scarf() {
        Accessory *p = new ScarfLadies();
        p -> input();
        return p;
    }
};


class Accessories_Men: public Factory{
public:
    Accessory* create_accessory_glasses(){
        Accessory* p = new GlassesMen();
        p -> input();
        return p;
    }
    Accessory* create_accessory_scarf(){
        Accessory* p = new ScarfMen();
        p -> input();
        return p;
    }
};

/// SINGLETON CLASS
/*
 *  Acest design pattern ne  ajuta cu proiectarea unei clase cu un
 *  singur obiect;
 *
 *  Ce deosebim aici este CONSTRUCTORUL PRIVAT, CAMPUL DE DATE STATIC care
 *  va fi un pointer catre obiectulde tipul clasei si care va reprezenta
 *  obiectul unic al clasei si METODA STATICA ce apeleaza constructorul privat
 *  daca nu a fost creata deja o instanta a clasei
 */

class Hat {

    char size; // care poate fi  S M L
    int price;
    static Hat* p;
    Hat(const Hat &ob)  {size = ob.size;  price = ob.price;}

public:
    ///Hat(): Accesory() {size = 'X';}
    Hat( double Price = 12.0, int Id = 0, char Size = 'X')  { price = Price; size = Size;}
    ~Hat()   { cout << "Hat destroyed"<<"\n";  }

    static Hat *get_Hat(){
        if(p == NULL) p = new Hat();
        return p;
    }

    char getSize() const;
    void setSize(char size);

    int getPrice() const;

    bool operator==(const type_info &ob);
    bool operator!=(const type_info &ob);

    void input() { cin >> size >> price;}
    void output() {  cout << size <<" " << price;}

    Hat& operator=(Hat&);
    friend ostream& operator<<(ostream& out, Hat& ob);
    friend istream& operator>>(istream& in, Hat& ob);

    void price_goes_up(int);
    void price_goes_down(int);

};

Hat* Hat:: p = NULL;
void Hat::price_goes_up(int x){
    price = price + price*x/100;
}

void Hat::price_goes_down(int x){
    price = price - price*x/100;
}

int Hat::getPrice() const {
    return price;
}




/// STRATEGY PATTERN
/* clasa mare JOB care "incapsuleaza" fiecare tip de job: casier, manager sau ajutor_client
 * (persoana care ajuta clientii si aseaza accesoriile la locul lor)
 * structura:    Employee -> JOB -> (CASIER, MANAGER, AJUTOR_CLIENT)
*/

class Job {
public:
    virtual void job() const = 0;

};


class Cashier: public Job {
public:
    void job() const { cout << "cashier" << endl;}
};

class Manager: public Job {
public:
    void job() const { cout << "manager" << endl;}
};


class Assistant_client: public Job {
public:
    void job() const { cout << "assistent_client" << endl;}

};

template <class T>
class Employee {
    string first_name, last_name;
    T salary;
    Job* name_job;

public:
    Employee(string LastName, string FirstName, Job* Name_Job, T N) {
        first_name = FirstName;
        last_name = LastName;
        name_job = Name_Job;
        salary = N;
    }

    void setName_Job(Job* new_job){
        if(name_job != NULL) delete name_job;
        name_job = new_job;
    }

    void post()
    {
        if(name_job == NULL) throw "You don't selected any job!";
        name_job -> job();
    }
    virtual ~Employee() {delete name_job;}

    void input() { cin >> last_name >> first_name; }
    void output() {
        cout << last_name <<" "<< first_name <<" " ;
        name_job->job();
    }


};


class Boutique
{
    vector <Employee <int> > employees;
    Accessory* accessories[200];
    int dimv, dimB, dimF, dimA;


public:
    Boutique(int DimV = 0) {dimv = DimV;}

    Boutique() /// constructor de initializare fara parametrii
    {   try {
            if(dimv < 0 )
                throw 101;
        }catch(...) {cout <<"error 101" << endl; }
    }


    ~Boutique() {cout << "Store distroyed" <<"\n"; }

    void read_accessoriesMen()
    {
        Factory* factory = new Accessories_Men();
        cout << "Write the number of men's accessories: ";
        /// dimensiunea vectorului accesoriiBarbati care are elemente de tip Factory
        cin >> dimB;
        for(int i = 0; i < dimB; i++)
        {   int type;
            cout <<"Type 1 for scarf or 2 for glasses" << endl;
            cin >> type; /// daca e 1 e esarfa, daca e 2 e ochelari
            if(type == 1) accessories[dimv++] = factory -> create_accessory_scarf();
            if(type == 2) accessories[dimv++] = factory -> create_accessory_glasses();

        }
    }



    void read_accessoriesLadies()
    {
        Factory* factory = new Accessories_Ladies();
        cout << "Write the number of ladies's accessories: ";
        /// dimensiunea vectorului accesoriiBarbati care are elemente de tip Factory
        cin >> dimF;
        for(int i=0; i<dimF; i++)
        {   int type;
            cout <<"Type 1 for scarf or 2 for glasses" << endl;
            cin >> type; /// daca e 1 e esarfa, daca e 2 e ochelari
            if(type == 1) accessories[dimv++] = factory -> create_accessory_scarf();
            if(type == 2) accessories[dimv++] = factory -> create_accessory_glasses();

        }

    }

    void output_accessories(){
        for(int i=0; i<dimv; i++)
                accessories[i] -> output();
    }

    void read_Employees()
    {
        Employee <int> a1("Asavoaei","Bianca", new Cashier(), 100);
        employees[dimA++] = a1;
        Employee <int> a2("Popa","Elena", new Cashier(), 200);
        employees[dimA++] = a2;
    }

    void ChangeJob(){
        for(int i=0; i<dimA; i++)
        {
            employees[i].post();
            employees[i].setName_Job(new Assistant_client());
            employees[i].post();
        }
    }

    void Output_price_changed(){
        Hat * p1 = Hat::get_Hat();
        cout << "The old price is ";
        cout << p1->getPrice() << endl;
        p1 -> price_goes_up(50);
        cout << "After price increase of 50%, the price is  ";
        cout << p1 ->getPrice() << endl;

        Hat * p2 = Hat:: get_Hat();
        cout << "The old price is ";
        cout << p2 -> getPrice() << endl;
        p2 -> price_goes_down(20);
        cout <<"After a discount of 20%, the price is ";
        cout << p2 -> getPrice() << endl;

    }

    void Write_Employees()
    {
        Employee <int> a("Asavoaei","Bianca", new Cashier(), 100);
        cout <<"The last job for miss Asavoaei Bianca was ";
        a.post();
        a.setName_Job(new Manager());
        cout <<"After 2 days of working for OOP project, the newest job for miss Asavoaei Bianca is ";
        a.post();
    }

    void Task_Manager(){
        cout << "The Manager asks you how many scarfs and glasses for ladies and men does we have in boutique?" << endl;

        int nrScarfL = 0, nrScarfM = 0, nrGlassesL = 0, nrGlassesM = 0;
        for(int i = 0; i < dimv; i++) {
            if (typeid(*accessories[i]) == typeid(ScarfLadies)) nrScarfL++;
            else if (typeid(*accessories[i]) == typeid(ScarfMen)) nrScarfM++;
            else if (typeid(*accessories[i]) == typeid(GlassesMen)) nrGlassesM++;
            else if(typeid(*accessories[i]) == typeid(GlassesLadies)) nrGlassesL++;
        }

        cout << "In our shop we got : " << nrScarfL <<" of scarfs for ladies, " << nrScarfM <<" of scarfs for men,";
        cout << nrGlassesL << " of glasses for ladies and " << nrGlassesM << " of glasses for men" << endl;
    }

};

void Meniu(){

    Boutique B(0);
    cout <<"Welcome in Gizzeh's Boutique, our accesories store!" << endl;
    cout <<"Look at our prices, we got the best offer!" << endl;
    B.Output_price_changed();

    cout <<"The team is changing. Our employees are promoted. Meet the team!" << endl;
    B.Write_Employees();

    cout <<"Become an employee and insert some products!" << endl;
    B.read_accessoriesLadies();
    B.read_accessoriesMen();

    cout <<"Now present the products to the clients!" << endl;
    B.Task_Manager();
    B.output_accessories();
}

int main() {

    Meniu();
    return 0;
}
