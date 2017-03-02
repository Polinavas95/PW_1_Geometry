//Вариант 4
//
//Реализовать геометрию со следующими параметрами:
//Расположить в плоскости XZ G4Trd G4CutTubs G4BoX и G4Sphere по вершинам вписанного в окружность квадрата
//в плоскости Y фигуры распологаться одна над другой

#include "DetGeometry.hh"

DetGeometry::DetGeometry() {
    world_sizeXYZ   = 50 * m;
    nist            = G4NistManager::Instance();
    world_mat       = nist->FindOrBuildMaterial("G4_AIR");
    solidWorld      = new G4Box("solWorld", 0.5*world_sizeXYZ, 0.5*world_sizeXYZ, 0.5*world_sizeXYZ);
    logicWorld      = new G4LogicalVolume(solidWorld, world_mat, "logWorld");
    physWorld       = new G4PVPlacement(0, G4ThreeVector(), logicWorld, "phyWorld", 0, false, 0);

    G4cout<<"Geometry of detector is build successfully\t\t\t\t\t\tOK!!!"<<G4endl;
}

DetGeometry::~DetGeometry() {}

G4VPhysicalVolume* DetGeometry::Construct(){
    G4Material* t_material = nist->FindOrBuildMaterial("G4_Fe");
    G4Material* ct_material = nist->FindOrBuildMaterial("G4_ANTHRACENE");
    G4Material* b_material = nist->FindOrBuildMaterial("G4_BARIUM_FLUORIDE");
    G4Material* s_material = nist->FindOrBuildMaterial("G4_BGO");

    return physWorld;
}


