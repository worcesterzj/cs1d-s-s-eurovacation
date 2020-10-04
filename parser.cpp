#include "parser.h"

parser::parser()
{

}

bool parser::read(std::vector<city*>& cities) {
    int thisLine = -1;

    QString path("data/cities/");               // Path to point to in "working directory" (same directory as the program's .exe)
    QDir dir;                                   // Qt Directory manager

    if(!dir.exists(path))                       // If the directory doesn't exist,
        dir.mkpath(path);                       // MAKE IT EXIST!!

    QFile cityin(path + "cit.sas");            // Path to the thingy
    QTextStream c(&cityin);

    if (!cityin.open(QIODevice::ReadOnly | QIODevice::Text))
        std::clog << "No cit.sas file found!\n";
    else{

        std::vector<city*> temp;

        while(!c.atEnd()){

            QString line = c.readLine();
            thisLine++;
            if(line == "")
                continue;
            if(line[0] == '@')      // Use @ to comment out a single line.
                continue;
            if(line[0] == '#'){
                city tempcity;
                QString readCity = c.readLine();
                thisLine++;

                while(readCity[0] != '#') {

                    if(readCity == "" || readCity[0] == '@'){
                        readCity = c.readLine();
                        thisLine++;
                        continue;
                    }
                    else if(readCity.startsWith("name") && readCity.contains('=')){
                        int startData = readCity.indexOf('=');


                        while(readCity[startData] == ' ' || readCity[startData] == '\t' || readCity[startData] == '=')
                            startData++;

                        readCity.remove(0, startData);
                        tempcity.setName(readCity);
                        readCity = c.readLine();
                        thisLine++;
                        continue;
                    }
                    else if(readCity.startsWith("country") && readCity.contains('=')){
                        int startData = readCity.indexOf('=');


                        while(readCity[startData] == ' ' || readCity[startData] == '\t' || readCity[startData] == '=')
                            startData++;

                        readCity.remove(0, startData);
                        tempcity.setParentCountry(readCity);

                        readCity = c.readLine();
                        thisLine++;
                        continue;
                    }
                    else if(readCity.startsWith("food") && readCity.contains('=') && readCity.contains('{')){
                        QString _food = c.readLine();
                        thisLine++;

                        while (_food[0] != '}'){
                            food tempfood;
                            tempfood.setName(_food.mid(_food.indexOf('(') + 1, (_food.indexOf(',') - _food.indexOf('(') - 1)));
                            tempfood.setPrice(_food.mid(_food.indexOf(',') + 2, _food.indexOf(')') - (_food.indexOf(',') + 2)).toDouble());

                            tempcity.addFoodItem(new food(tempfood));
                            _food = c.readLine();
                            thisLine++;
                        }

                        readCity = c.readLine();
                        thisLine++;

                        continue;
                    }
                    else{
                        std::clog << "Error: Detected unreadable line (line @ " << thisLine << "): " << readCity.toStdString() << '\n'
                                  << "Aborting.\n";
                        return false;
                    }
                }

                temp.push_back(new city(tempcity));

            }
            else{
                std::clog << "Error: Detected unreadable line (line @ " << thisLine << "): " << line.toStdString() << '\n'
                          << "Aborting.\n";
                return false;
            }
        }

        cities = temp;

        cityin.close();
    }

    std::clog << "cit.sas successfully read.\n";

    return true;
}
