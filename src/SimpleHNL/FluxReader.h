//----------------------------------------------------------------------------
/*!

  This reads in flux histograms and constructs SimpleHNL objects
  with appropriate energy + momentum + vertex position + pol

  The couplings to SM are not relevant at this stage
  However, labelling the flux with its couplings should be so we don't lose track

  Solution: Read in couplings directly from the *file name*. 

\namespace  genie::HNL::FluxReader

\brief      Reads in flux at MINERvA centre

\author     John Plows <komninos-john.plows@physics.ox.ac.uk>

\created    January 5th, 2021

\cpright    ??? - TBD

 */
//----------------------------------------------------------------------------
// TODO: Decide naming convention for flux file names
//       Calculate polarisation vector magnitude in 3-body HNL production
//       Decide a PDG numbering scheme
//       Decide a fluxRoot string
//----------------------------------------------------------------------------

#ifndef JFLUXREADER_H
#define JFLUXREADER_H

// -- ROOT includes
#include "TFile.h"
#include "TH1.h"
#include "TH2.h"
#include "TH3.h"

// -- GENIE includes

#include "Conventions/Units.h"
#include "Messenger/Messenger.h"

#include "Enums.h"
#include "KinUtils.h"
#include "SimpleHNL.h"

//#include "HNLAuxiliary/KinUtils.h"

namespace genie{
namespace HNL{

    class SimpleHNL;

    namespace FluxReader{

	namespace gc  = ::genie::constants;
	namespace gh  = ::genie::HNL;
	namespace ghe = ::genie::HNL::enums;
	namespace ghu = ::genie::HNL::utils;

	extern std::string fPath; // flux file to poke
	extern ghe::parent_t fParent; // which component of the flux to analyse
	extern ghe::nutype_t fNuType; // which HNL kind do I want to analyse0

	extern double fmN; // HNL mass
	extern double fUe, fUm, fUt; // SM couplings
	extern int fPDG, fParPDG;
	extern bool fMaj; // is Majorana?
	
	/// initialise bare HNL parameters
	inline void bareInit( ){
	    fPDG = 0; fmN = 0.; fUe = 0.; fUm = 0.; fUt = 0.; fMaj = false; }
	
	inline void setMass( const double mN ){ fmN = mN; }
	inline void setCouplings( const double Ue42, const double Umu42,
				  const double Ut42 ){
	    fUe = Ue42; fUm = Umu42; fUt = Ut42; }
	inline void setPDG( const int pdg ){ fPDG = pdg; }
	inline void setMaj( const bool maj ){ fMaj = maj; }

	/// perform selections from input files

	std::string selectCoup( const double Ue42, const double Umu42, const double Ut42 );
	int selectMass( const double mN );
	void selectFile( const std::string strconf,
			 const double Ue42, const double Umu42, const double Ut42,
			 const double mN ); // find but don't open the file

	void selectParent( const int parPDG );
	void selectNuType( const int HType );

	template< typename T >
	T * getFluxHist( std::string fin, std::string hName,
			 ghe::parent_t par, ghe::nutype_t HType ); // read in hist of type T
	
	double generatePolMag( const int lPDG, const int parPDG );
	std::vector< double > * generatePolDir( const int parPDG, const int HType );

	std::vector< double > * generateVtx3X( const int parPDG, const int HType );
	double generateVtxT( const int parPDG, const int HType );

	double generateVtxE( const int parPDG, const int HType );
	std::vector< double > * generateVtx3P( const int parPDG, const int HType,
					       const double inE = -1.0 );

	/// interface to constructor
	genie::HNL::SimpleHNL generateHNL( ); //default, uses this namespace's globals
	genie::HNL::SimpleHNL generateHNL( const int PDG, const int parPDG,
				   const double mN, const double Ue42,
				   const double Umu42, const double Ut42 );

	/// set all other stuff from flux prediction
	void setFluxInfo( genie::HNL::SimpleHNL sh );

    } // namespace FluxReader

} // namespace HNL
} // namespace genie

#endif // #ifndef JFLUXREADER_H
