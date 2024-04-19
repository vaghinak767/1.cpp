#include "cell.h"

Cell::Cell()
{
    m_val = "\0";
}

Cell::Cell(const Cell& obj) : m_val{obj.m_val}
{}

Cell::Cell(Cell&& rhv) noexcept : m_val{rhv.m_val}
{
    rhv.m_val = "\0";
}

Cell::Cell(int val)
{
    m_val = std::to_string(val);
}

Cell::Cell(double val)
{
    m_val = std::to_string(val);
}

Cell::Cell(std::string val)
{
    m_val = val;
}

Cell::Cell(char val)
{
    m_val = std::string(1, val);
}

Cell::Cell(bool val)
{
    m_val = val? "true" : "false";
}

Cell::Cell(const std::vector<int>& val)
{
    m_val = '[';
    int size = val.size();
    if(size != 0)
        m_val += val[0];
    for(int i = 1; i < size; ++i)
    {
        m_val += ',' + val[i];
    }
    m_val += ']';
}

const Cell& Cell::operator=(const Cell& rhv)
{
    m_val = rhv.m_val;
    return *this;
}

const Cell& Cell::operator=(Cell&& rhv) noexcept
{
    m_val = rhv.m_val;
    rhv.m_val = "\0";
    return *this;
}

const Cell& Cell::operator=(int val)
{
    m_val = std::to_string(val);
    return *this;
}

const Cell& Cell::operator=(double val)
{
    m_val = std::to_string(val);
    return *this;
}

const Cell& Cell::operator=(std::string val)
{
    m_val = val;
    return *this;
}

const Cell& Cell::operator=(char val)
{
    m_val = std::string(1, val);
    return *this;
}

const Cell& Cell::operator=(bool val)
{
    m_val = val? "true" : "false";
    return *this;
}

const Cell& Cell::operator=(const std::vector<int>& rhv)
{
    m_val = '[';
    int size = rhv.size();
    if(size != 0)
        m_val += rhv[0];
    for(int i = 1; i < size; ++i)
    {
        m_val += ',' + rhv[i];
    }
    m_val += ']';
    return *this;
}

Cell::operator int()
{
    return std::stoi(m_val);
}

Cell::operator double()
{
    return std::stod(m_val);
}

Cell::operator std::string()
{
    return m_val;
}

Cell::operator char()
{
    return m_val[0];
}

Cell::operator bool()
{
    int tmp = std::stoi(m_val);
    return m_val == "true";
}
