#include "tools/info.h"

static const string filePath = "src/data/id.txt";

void getDate(string& dest){
    time_t rawtime;
    time (&rawtime);
    struct tm* timeinfo = localtime(&rawtime);

    stringstream ss;
    ss << timeinfo->tm_year + 1900 << "-" << timeinfo->tm_mon + 1 << "-" << timeinfo->tm_mday;
    dest = ss.str();
}

void genID(string& dest, char type){
    int uid = 0, gid = 0, oid = 0; //分别对应user, good, order

    ifstream ifs(filePath);
    if(ifs.is_open()) {
        ifs >> uid >> gid >> oid;
        ifs.close();
    }

    int id = 0;
    
    switch(type) {
        case 'U': id = uid++; break;
        case 'G': id = gid++; break;
        case 'O': id = oid++; break;
    }

    ofstream ofs(filePath);
    if(ofs.is_open()) {
        ofs << uid << " " << gid << " " << oid << endl;
        ofs.close();
    }

    stringstream ss;
    ss << type << setw(5) << setfill('0') << id;
    dest = ss.str();
}