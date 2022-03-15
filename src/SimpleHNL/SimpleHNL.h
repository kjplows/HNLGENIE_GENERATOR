//----------------------------------------------------------------------------
/*!

  Class for the HNL itself
  A `SimpleHNL` object is *not* one individual HNL, but rather a *class* of HNLs:
  i.e. all those HNL with M = 245 MeV and couplings 0:1:0 .	
  Then we can construct one such SimpleHNL and make, say, 1M particles out of it,
  each with its own beta, 4P, origin vertex & parent, (polarisation?),
  & decay mode + kinematics.

\namespace  genie::HNL

\class      genie::HNL::SimpleHNL

\brief      HNL object

\author     John Plows <komninos-john.plows@physics.ox.ac.uk>

\created    December 10th, 2021

\cpright    ??? - TBD

*/
//----------------------------------------------------------------------------
// TODO: write exception for (set E > fMass)??
//       Figure out way to sample co-produced lepton direction for HNL polVector
//----------------------------------------------------------------------------

#ifndef JSIMPLEHNL_H
#define JSIMPLEHNL_H

#include "Conventions/Constants.h"
//#include "HNLAuxiliary/DecayChannels.h"
//#include "HNLAuxiliary/DecaySelector.h"
//#include "HNLAuxiliary/Defaults.h"
//#include "HNLAuxiliary/Enums.h"  
//#include "HNLAuxiliary/Stepper.h"
#include "Messenger/Messenger.h"

#include "DecayChannels.h"
#include "DecaySelector.h"
#include "Defaults.h"
#include "Enums.h"  
#include "Stepper.h"

namespace genie {
    
    namespace HNL {
	
	class SimpleHNL
	{
	public:
	    inline SimpleHNL( std::string name, int index ) :
		fName( name ), fIndex( index ),
		fPDG( defPDG ), fParentPDG( defParPDG ), fMass( defMass ),
		fUe42( defUe42 ), fUmu42( defUmu42 ), fUt42( defUt42 ),
		fIsMajorana( false ),
		fValidChannels(
		    genie::HNL::Selector::GetValidChannelWidths( defMass,
						defUe42, defUmu42, defUt42,
						false ) ),
		fCoMLifetime(
		    genie::HNL::Selector::CalcCoMLifetime( defMass,
					  defUe42, defUmu42, defUt42,
					  false ) )
	    { } /// default c'tor

	    inline SimpleHNL(
		std::string name, int index,
		const int PDG, const int parPDG, const double mass,
		const double Ue42, const double Umu42, const double Ut42,
		const bool IsMajorana
		) : fName( name ), fIndex( index ),
		    fPDG( PDG ), fParentPDG( parPDG ), fMass( mass ),
		    fUe42( Ue42 ), fUmu42( Umu42 ), fUt42( Ut42 ),
		    fIsMajorana( IsMajorana ),
		    fValidChannels(
			genie::HNL::Selector::GetValidChannelWidths( mass,
						    Ue42, Umu42, Ut42,
						    IsMajorana ) ),
		    fCoMLifetime(
			genie::HNL::Selector::CalcCoMLifetime( mass,
					      Ue42, Umu42, Ut42,
					      IsMajorana ) )
	    { } /// normal constructor

	    inline ~SimpleHNL( ) { }

	    // TODO: Getters, setters, calculators

	    // Getters

	    inline const std::string GetName( ) { return fName; }

	    inline const int    GetIndex( ) { return fIndex; }

	    inline const double GetMass( ) { return fMass; }

	    inline const std::vector< double > GetCouplings( ) {
		std::vector< double > coupVec;
		coupVec.emplace_back( fUe42 );
		coupVec.emplace_back( fUmu42 );
		coupVec.emplace_back( fUt42 );
		return coupVec; }

	    inline const bool   GetIsMajorana( ) { return fIsMajorana; }

	    inline const double GetBeta( ) { return fBeta; }

	    inline const double GetGamma( ) { return fGamma; }

	    inline const double GetCoMLifetime( ) { return fCoMLifetime; }

	    inline const double GetLifetime( ) { /* return fLifetime; */
		return CalcLifetime( fGamma ); }

	    inline const int    GetPDG( ) { return fPDG; }

	    inline const int    GetParentPDG( ) { return fParentPDG; }

	    inline const genie::HNL::enums::nutype_t GetHType( ) { return fHType; }

	    inline const double GetDecayThrow( ) { return fDecayThrow; }

	    inline const double GetSelectThrow( ) { return fSelectThrow; }

	    inline const genie::HNL::enums::HNLDecay_t GetDecayMode( ) { return fDecayMode; }

	    inline std::vector< double > GetDecay4VX( ) {
		std::vector< double > decVec;
		decVec.emplace_back(fT);
		decVec.emplace_back(fX);
		decVec.emplace_back(fY);
		decVec.emplace_back(fZ);
		return decVec; }

	    inline std::vector< double > GetOrigin4VX( ) {
		std::vector< double > oriVec;
		oriVec.emplace_back(fT0);
		oriVec.emplace_back(fX0);
		oriVec.emplace_back(fY0);
		oriVec.emplace_back(fZ0);
		return oriVec; }

	    inline std::vector< double > Get4VP( ) {
		std::vector< double > momVec;
		momVec.emplace_back(fE);
		momVec.emplace_back(fPx);
		momVec.emplace_back(fPy);
		momVec.emplace_back(fPz);
		return momVec; }

	    inline std::vector< double > GetBetaVec( ) {
		std::vector< double > betaVec;
		const double mom = GetMomentum( );
		const int pxMod = ( fPx < 0.0 ) ? -1 : 1;
		const int pyMod = ( fPy < 0.0 ) ? -1 : 1;
		const int pzMod = ( fPz < 0.0 ) ? -1 : 1;
		betaVec.emplace_back( pxMod * fPx / fE * fPx / mom );
		betaVec.emplace_back( pyMod * fPy / fE * fPy / mom );
		betaVec.emplace_back( pzMod * fPz / fE * fPz / mom );
		return betaVec; }

	    inline const double GetMomentum( ) { 
	      return fPmag; 
	    }

	    inline const double GetPolarisationMag( ) { return fPol; }
	    inline const std::vector< double > * GetPolarisationDir( ) {
		return fPolDir; }

	    inline const std::map< genie::HNL::enums::HNLDecay_t, double > GetValidChannels( ) {
		return fValidChannels; }

	    inline const std::map< genie::HNL::enums::HNLDecay_t, double > GetInterestingChannels( ) {
		return fInterestingChannels; }

	    // setters

	    inline void SetName( const std::string name ) { fName = name; }

	    inline void SetIndex( const int idx ) { fIndex = idx; }

	    inline void SetEnergy( const double E ) { // TODO make exception & error code!!
		// updates beta, gamma, 4P, lifetime. Doesn't change angles.
		if( E < fMass ) { LOG( "SimpleHNL", pERROR ) << 
		    "genie::HNL::SimpleHNL:: Set E too low." <<
			"\nE = " << E << ", M = " << fMass; exit(3); }
		double mom3 = std::sqrt( E*E - fMass*fMass );
		double oldmom = GetMomentum( );
		fPmag = mom3;		    
		fPx = mom3 / std::sqrt(3.0); fPy = mom3 / std::sqrt(3.0); fPz = mom3 / std::sqrt(3.0);
		fE = E;
		fBeta = CalcBeta( E, mom3 );
		fGamma = CalcGamma( fBeta );
		fLifetime = fCoMLifetime / ( fGamma * ( 1.0 + fBeta ) );
	    }

	    inline void SetBeta( const double bet ) {
		// TODO: exception for beta >= 1
		fBeta = bet;
		fGamma = CalcGamma( bet );
		fE = fGamma * fMass;
		double oldmom = fPmag;
		fPmag = std::sqrt( fE*fE - fMass*fMass );

		fPx *= fPmag / oldmom; fPy *= fPmag / oldmom; fPz *= fPmag / oldmom;

		fLifetime = fCoMLifetime / ( fGamma * ( 1.0 + bet ) );
	    }

	    inline void SetMomentumAngles( double theta, double phi ) {
		/// does not change magnitude
		// bring angles into [0,\pi]*[0,2\pi) 
		if( std::abs( theta ) > genie::constants::kPi ) {
		    const int nabs = std::floor( std::abs( theta ) / genie::constants::kPi );
		    theta += ( theta < 0 ) ? nabs * genie::constants::kPi : -nabs * genie::constants::kPi; }
		if( std::abs( phi ) > 2.0 * genie::constants::kPi ) {
		    const int nabs = std::floor( std::abs( phi ) / ( 2.0 * genie::constants::kPi ) );
		    phi += ( phi < 0 ) ? nabs * 2.0 * genie::constants::kPi : -nabs * 2.0 * genie::constants::kPi; }
		phi += ( phi < 0 ) ? 2.0 * genie::constants::kPi : 0.0;

		if( theta < 0 ){
		    double ap = ( phi < genie::constants::kPi ) ? genie::constants::kPi : -genie::constants::kPi;
		    theta *= -1.0; phi += ap; 
		}

		fPx = fPmag * std::sin( theta ) * std::cos( phi );
		fPy = fPmag * std::sin( theta ) * std::sin( phi );
		fPz = fPmag * std::cos( theta );
	    }

	    inline void SetMomentumDirection( double ux, double uy, double uz ) {
		/// does not change magnitude
		// TODO polish the null exception
		if( ux == 0.0 && uy == 0.0 && uz == 0.0 ){
		    LOG( "SimpleHNL", pERROR ) << 
		      "genie::HNL::SimpleHNL::SetMomentumDirection:: " <<
		      "Zero vector entered. Exiting."; exit(3); }
		const double umag = std::sqrt( ( ux*ux + uy*uy + uz*uz ) );
		const double invu = 1.0 / umag;
		ux *= invu; uy *= invu; uz *= invu;
		fPx = fPmag * ux; fPy = fPmag * uy; fPz = fPmag * uz;
	    }

	    inline void Set4Momentum( const std::vector< double > fourP ){
		SetEnergy( fourP.at(0) ); // also takes care of Pmag
		SetMomentumDirection( fourP.at(1), fourP.at(2), fourP.at(3) ); }

	    inline void SetPolMag( const double pm ){
		// TODO polish this exception
		if( pm < -1.0 || pm > 1.0 ){
		    LOG( "SimpleHNL", pERROR ) << 
		      "genie::HNL::SimpleHNL::SetPolMag:: " <<
		      "Pol.vec. magnitude must be in [-1,1]. Exiting."; exit(3); }
		fPol = pm; }

	    inline void SetPolarisationDirection( const double plx,
						  const double ply, const double plz ){
		if( plx == 0.0 && ply == 0.0 && plz == 0.0 ){
		    LOG( "SimpleHNL", pERROR ) << 
		      "genie::HNL::SimpleHNL::SetPolarisationDirection:: " <<
		      "Zero vector entered. Exiting."; exit(1); }
		const double PM = std::sqrt( plx*plx + ply*ply * plz*plz );
		fPolUx = plx / PM; fPolUy = ply / PM; fPolUz = plz / PM;
	        fPolDir = new std::vector< double >( );
		fPolDir->emplace_back( fPolUx ); fPolDir->emplace_back( fPolUy );
		fPolDir->emplace_back( fPolUz ); }

	    inline void SetProdVtx( const std::vector< double > fourV ){
		fT0 = fourV.at(0); fX0 = fourV.at(1);
		fY0 = fourV.at(2); fZ0 = fourV.at(3); }

	    inline void SetDecayVtx( const std::vector< double > fourV ){
		fT = fourV.at(0); fX = fourV.at(1);
		fY = fourV.at(2); fZ = fourV.at(3); 
	    }

	    inline void SetInterestingChannels(
		const std::map< genie::HNL::enums::HNLDecay_t, double > gammaMap ){
		fInterestingChannels = gammaMap; }

	    inline void SetDecayMode( const genie::HNL::enums::HNLDecay_t decayMode ){
		fDecayMode = decayMode; }

	    inline void SetParentPDG( const int parPDG ){
		fParentPDG = parPDG; }

	    inline void SetPDG( const int PDG ){
		fPDG = PDG; }

	    inline void SetHType( const genie::HNL::enums::nutype_t HType ){
		fHType = HType; }
	    
	protected:
	    // default c'tor values
	    int defPDG = genie::HNL::defaults::HNLDefaultPDG; 
	    int defParPDG = genie::HNL::defaults::HNLDefaultParPDG;
	    double defMass  = genie::HNL::defaults::HNLDefaultMass;
	    double defUe42  = genie::HNL::defaults::HNLDefaultECoup;
	    double defUmu42 = genie::HNL::defaults::HNLDefaultMuCoup;
	    double defUt42  = genie::HNL::defaults::HNLDefaultTauCoup;

	    // basic calculators
	    inline const double CalcBeta( const double E, const double P3 ) {
		return P3 / E; }
	    
	    inline const double CalcGamma( const double bet ) {
		return std::sqrt( 1.0 / ( 1.0 - bet*bet ) ); }

	    inline const double CalcLifetime( const double gam ) {
	      return fCoMLifetime * gam; } // rest-to-lab transf

	private:

	    mutable std::string      fName;
	    mutable int              fIndex;
	    mutable int              fPDG;
	    mutable int              fParentPDG;
	    mutable double     fMass;
	    mutable double     fUe42, fUmu42, fUt42;
	    mutable bool       fIsMajorana;
	    mutable std::map< genie::HNL::enums::HNLDecay_t, double > fValidChannels;
	    mutable double     fCoMLifetime;

	    mutable genie::HNL::enums::nutype_t    fHType;
	    
	    mutable double           fDecayThrow;  // determines where decay happens
	    mutable double           fSelectThrow; // determines what channel to decay to
	    mutable genie::HNL::enums::HNLDecay_t  fDecayMode;
	    
	    mutable std::map< genie::HNL::enums::HNLDecay_t, double > fInterestingChannels;
	    
	    mutable double                  fBeta, fGamma;
	    mutable double                  fLifetime;
	    mutable double                  fT, fX, fY, fZ; // LAB, decay
	    mutable double                  fT0, fX0, fY0, fZ0; // LAB, origin
	    mutable double                  fE, fPmag, fPx, fPy, fPz; // LAB, momentum
	    mutable double                  fPol; // polarisation magnitude
	    mutable double                  fPolUx, fPolUy, fPolUz;
	    mutable std::vector< double > * fPolDir; // polarisation direction
	    
	}; // class SimpleHNL

    } // namespace HNL

} // namespace genie

#endif // #ifndef JSIMPLEHNL_H
