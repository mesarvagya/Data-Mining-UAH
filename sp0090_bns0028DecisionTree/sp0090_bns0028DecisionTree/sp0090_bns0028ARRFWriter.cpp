
/**
 sp0090_bns0028ARRFWriter.cpp
 Sarvagya Pant
 Bidhya Nandan Sharma
 April 3, 2017
 **/


#include "sp0090_bns0028ARRFWriter.hpp"
#include <cassert>

#define SPACE " "


ArffWriter::ArffWriter(std::string fileName)
{
    outFile.open(fileName.c_str());
}

void ArffWriter::relation_writer(std::string relationName)
{
    if (!outFile)
    {
        std::cerr << "Error: Could not open the file" << std::endl;
    }
    outFile << "@relation" << SPACE << relationName << std::endl;
}

void ArffWriter::attributes_writter(std::vector<std::string> attrNames, std::vector<std::string> attrVals)
{
    if (!outFile)
    {
        std::cerr << "Error: Could not open the file" << std::endl;
    }
    outFile << std::endl;
    assert(attrNames.size() == attrVals.size());
    for (int i=0; i<(int)attrNames.size(); i++)
    {
        outFile << "@attribute" << SPACE << attrNames[i] << SPACE << attrVals[i] << std::endl;
    }
}

void ArffWriter::data_writer(std::vector<std::vector<string> > data, std::vector<string> classAttr,  bool includeClass, std::string delimeter)
{
    if (!outFile)
    {
        std::cerr << "Error: Could not open the file" << std::endl;
    }
    outFile << std::endl;
    outFile << "@data" << std::endl;
    if (includeClass && !classAttr.empty()) { assert(data.size() - 1 == classAttr.size()); }
    
    outFile << std::showpoint;
    for(int i=1; i<(int)data.size(); i++)
    {
        for(int j=0; j<(int)data[0].size(); j++)
        {
            outFile << delimeter << data[i][j];
        }
        if (includeClass && !classAttr.empty()) { outFile << delimeter << classAttr[i-1]; }
        outFile << std::endl;
    }
    outFile.close();
}

void ArffWriter::single_line_writer(std::string singleLine)
{
    if (!outFile)
    {
        std::cerr << "Error: Could not open the file" << std::endl;
    }
    outFile << singleLine << std::endl;
}


