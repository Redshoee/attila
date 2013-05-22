////////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Parser/IExtractor.h"

using namespace std;
using namespace dxcodegen::Parser;

////////////////////////////////////////////////////////////////////////////////

IExtractor::IExtractor(string& cadena, bool verbose) :
m_cadena(cadena),
m_verbose(verbose)
{
}

////////////////////////////////////////////////////////////////////////////////

IExtractor::~IExtractor()
{
}

////////////////////////////////////////////////////////////////////////////////

void IExtractor::Extract()
{
  MatchResults resultat;
  do {
    resultat.Clear();
  	resultat = Match(m_cadena);
    if (resultat.matched)
    {
      Parse(resultat);
    }
  } while(resultat.matched);
}

////////////////////////////////////////////////////////////////////////////////
