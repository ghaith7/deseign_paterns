#include <string>
#include <iostream>
class IPathType{
    public:
        virtual std::string calculate_path(std::string destination) =0;
};

class CarPath : public IPathType{
    public:
        std::string calculate_path(std::string destination) override{
            return "going to "+ destination+" always takes 5 mins by car.";
        }
};

class OnFootPath : public IPathType{
    public:
        std::string calculate_path(std::string destination) override{
            return "Good Idea! it's healthier to walk to" +destination + "but it takes 30min.";
        }
};

class PublicTransport : public IPathType{
    public:
        std::string calculate_path(std::string destination) override{
            return "much cheaper than by car but it takes 5 mins of waiting at the station and 5 mins to reach "+destination+" station.";
        }
};

class Maps{
    private:
        std::string destination;
        IPathType* selected_pathtype;
    public:
        void setDestination(std::string destination){
            this->destination = destination;
        }
        void setPathtype(IPathType* selected_pathtype){
            this->selected_pathtype = selected_pathtype;
        }
        void print_path(){
            std::string path = this->selected_pathtype->calculate_path(this->destination);
            std::cout << path << std::endl;
        }
};

int main(){
    Maps maps;
    std::string destination = "kram";
    OnFootPath marche;
    maps.setDestination(destination);
    maps.setPathtype(&marche);
    maps.print_path();
}