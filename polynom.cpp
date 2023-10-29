#include <iostream>
#include <stdexcept>
#include <vector>
#include "include/polynom.h"

using std::vector;

Polynomial::~Polynomial(){};    

Polynomial::Polynomial (vector<int> &&coeff, vector<int> &&deg)
  : coefficients { std::move(coeff) }
  , degrees { std::move(deg) }
  {
    if (coeff.size() != deg.size())
      throw std::invalid_argument("The parameters must be equal size!");
  }

void Polynomial::print() const
{
  for (int i = 0; i < coefficients.size(); ++i)
    {
      if (coefficients[i] != 0)
	{
	  std::cout << coefficients[i] << "x^" << degrees[i];
	  
	  if (i != coefficients.size() - 1)
	    std::cout << " + ";
	}
    }
  std::cout << std::endl;
}

// copy constructor
Polynomial::Polynomial(const Polynomial &src)
  : coefficients { src.coefficients }
  , degrees { src.degrees }
{
  if (src.coefficients.empty() || src.degrees.empty())
    throw std::invalid_argument("Invalid source polynomial!");
}

Polynomial Polynomial::operator+ (const Polynomial &rhs) const 
{
  if (coefficients.empty() || degrees.empty() ||
      rhs.coefficients.empty() || rhs.degrees.empty())
    {
      throw std::invalid_argument("Inavalid polynomial!");
    }
  
  auto result(*this);

  for (int i = 0; i < rhs.degrees.size(); i++)
    {
      int degree = rhs.degrees[i];
      int coefficient = rhs.coefficients[i];
      bool termFound = false;
    
      for (int j = 0; j < result.degrees.size(); j++)
	{
	  if (result.degrees[j] == degree)
	    {
	      result.coefficients[j] += coefficient;
	      termFound = true;
	      break;
	    }
	}

      if (!termFound)
	{
	  result.degrees.push_back(degree);
	  result.coefficients.push_back(coefficient);
	}
    }

   return result;
}

Polynomial Polynomial::operator - (const Polynomial &rhs) const
{
  if (coefficients.empty() || degrees.empty() ||
      rhs.coefficients.empty() || rhs.degrees.empty())
    {
      throw std::invalid_argument("Inavalid polynomial!");
    }

  auto result(*this);

  for (int i = 0; i < rhs.degrees.size(); i++)
    {
      int degree = rhs.degrees[i];
      int coefficient = rhs.coefficients[i];
      bool termFound = false;
    
      for (int j = 0; j < result.degrees.size(); j++)
	{
	  if (result.degrees[j] == degree)
	    {
	      result.coefficients[j] -= coefficient;
	      termFound = true;
	      break;
	    }
	}

      if (!termFound)
	{
	  result.degrees.push_back(degree);
	  result.coefficients.push_back(coefficient);
	}
    }

  return result;
}

  Polynomial Polynomial::operator * (const Polynomial &rhs) const
{
  if (coefficients.empty() || degrees.empty() ||
      rhs.coefficients.empty() || rhs.degrees.empty())
    {
      throw std::invalid_argument("Inavalid polynomial!");
    }

  auto result(*this);
  
  for (int i = 0; i < degrees.size(); i++)
  {
    for (int j = 0; j < rhs.degrees.size(); j++)
    {
      int degree = degrees[i] + rhs.degrees[j];
      int coefficient = coefficients[i] * rhs.coefficients[j];
      bool termFound = false;
      
      for (int k = 0; k < result.degrees.size(); k++)
      {
        if (result.degrees[k] == degree)
        {
          result.coefficients[k] += coefficient;
          termFound = true;
          break;
        }
      }
      
      if (!termFound)
      {
        result.degrees.push_back(degree);
        result.coefficients.push_back(coefficient);
      }
    }
  }

  return result;
}

Polynomial &Polynomial::operator ++ ()
{
  for (int i = 0; i < this->coefficients.size(); i++)
    ++this->coefficients[i];

  return *this;
}

Polynomial &Polynomial::operator -- ()
{
  for (int i = 0; i < this->coefficients.size(); i++)
    --this->coefficients[i];
  
  return *this;
}


 
