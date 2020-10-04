#include "serializer.h"


serializer::serializer()
{

}

void serializer::write(const std::vector<city*>& cities) {

    QString path("data/cities/");               // Path to point to in "working directory" (same directory as the program's .exe)
    QDir dir;                                   // Qt Directory manager

    if(!dir.exists(path))                       // If the directory doesn't exist,
        dir.mkpath(path);                       // MAKE IT EXIST!!

    QFile cityout(path + "cit.sas");            // Path to the thingy
    QTextStream c(&cityout);

    if (!cityout.open(QIODevice::WriteOnly | QIODevice::Text))
        std::clog << "No cit.sas file found!\n";
    else{
        c << "@ This file was generated by the program.\n\n";

        for(int i = 0; i < int(cities.size()); i++) {
            c << "# " << cities[i]->getName() << "\n"
              << "name = " << cities[i]->getName() << "\n"
              << "country = " << cities[i]->getParentCountry() << "\n"
              << "food = {\n";

            for(auto f : cities[i]->getFoodRef())
                c << "\t(" << f->getName() << ", " << QString::number(f->getPrice()) << ")\n";

            c << "}\n"
              << "# End of " << cities[i]->getName() << "\n\n";
        }

        cityout.close();
        std::clog << "cit.sas successfully written.";
    }
}
