#include "bst.hpp"
#include <iostream>
#include <string>

int main() {
    struct {
        std::string name;
        int length;
    } MouthNode, YoungsTributary, ElchomanTributary, LewisTributary,WilametteTributary, BonnevilleDam, WindTributary, HoodTributary, DallesDam, DeschutesTributary, JohnDayDam, McNaryDam, PriestRapidsDam, WanapumDam, RockIslandsDam, ChiefJosephDam, SnakeRiverTributary, ClearwaterRiverTributary, SpokaneRiverConfluenceTributary, SpokaneRiverLowerFallsDam;
    MouthNode.name = "Mouth: Pacific Ocean", MouthNode.length = 856;
    YoungsTributary.name = "Youngs Tributary", YoungsTributary.length = 844;
    ElchomanTributary.name = "Elchoman Tributary", ElchomanTributary.length = 818;
    LewisTributary.name = "Lewis Tributary", LewisTributary.length = 769;
    WilametteTributary.name = "Wilamette Tributary", WilametteTributary.length = 755;
    BonnevilleDam.name = "Bonneville Dam", BonnevilleDam.length = 710;
    WindTributary.name = "Wind Tributary", WindTributary.length = 701;
    HoodTributary.name = "Hood Tributary", HoodTributary.length = 687;
    DallesDam.name = "Dalles Dam", DallesDam.length = 664;
    DeschutesTributary.name = "Deschutes Tributary", DeschutesTributary.length = 652;
    JohnDayDam.name = "John Day Damn", JohnDayDam.length = 640;
    McNaryDam.name = "McNary Dam", McNaryDam.length = 564;
    PriestRapidsDam.name = "Priest Rapids Dam", PriestRapidsDam.length = 459;
    WanapumDam.name = "Wanapum Dam", WanapumDam.length = 441;
    RockIslandsDam.name = "Rock Islands Dam", RockIslandsDam.length = 400;
    ChiefJosephDam.name = "Chief Joseph Dam", ChiefJosephDam.length = 311;
    SnakeRiverTributary.name = "Snake River Tributary", SnakeRiverTributary.length = 295;
    ClearwaterRiverTributary.name = "Clearwater River Tributary", ClearwaterRiverTributary.length = 280;
    SpokaneRiverConfluenceTributary.name = "Spokane River Confluence Tributary", SpokaneRiverConfluenceTributary.length = 111;
    SpokaneRiverLowerFallsDam.name = "Spokane River Lower Fall's Dam", SpokaneRiverLowerFallsDam.length = 0;

    BST tree;
    tree.insert(MouthNode.name, MouthNode.length);
    tree.insert(YoungsTributary.name, YoungsTributary.length);
    tree.insert(ElchomanTributary.name, ElchomanTributary.length);
    tree.insert(LewisTributary.name, LewisTributary.length);
    tree.insert(WilametteTributary.name, WilametteTributary.length);
    tree.insert(WindTributary.name, WindTributary.length);
    tree.insert(HoodTributary.name, HoodTributary.length);
    tree.insert(DeschutesTributary.name, DeschutesTributary.length);
    tree.insert(SnakeRiverTributary.name, SnakeRiverTributary.length);
    tree.insert(ClearwaterRiverTributary.name, ClearwaterRiverTributary.length);
    tree.insert(SpokaneRiverConfluenceTributary.name, SpokaneRiverConfluenceTributary.length);
    tree.insert(BonnevilleDam.name, BonnevilleDam.length);
    tree.insert(DallesDam.name, DallesDam.length);
    tree.insert(JohnDayDam.name, JohnDayDam.length);
    tree.insert(McNaryDam.name, McNaryDam.length);
    tree.insert(PriestRapidsDam.name, PriestRapidsDam.length);
    tree.insert(WanapumDam.name, WanapumDam.length);
    tree.insert(RockIslandsDam.name, RockIslandsDam.length);
    tree.insert(ChiefJosephDam.name, ChiefJosephDam.length);
    tree.insert(SpokaneRiverLowerFallsDam.name, SpokaneRiverLowerFallsDam.length);

    std::cout << "\n********************************************************************\n";
    std::cout << "This Binary Tree includes 20 Nodes of points along the Columbia River from the Mouth (the Pacific Ocean)\n" << "to the Spokane River Lower Falls Dam. The tributarys are inserted first, followed by dams in the river.\n" << "Each node has its name and length from the Spokane River Lower Falls Dam stored in a struct, and will print as the Node is reached in user-led traversal.";
    std::cout << "\n********************************************************************\n";

    std::cout << "\nIn-order traversal: ";
    tree.in_order_traversal();
    std::cout << ("\n");
    std::cout << "Root is " << tree.get_root()->name << std::endl;

    /*
    std::cout << "Pre-order traversal: ";
    tree.pre_order_traversal();

    std::cout << "Post-order traversal: ";
    tree.post_order_traversal();
    */
    std::cout << "Tree structure:" << std::endl;
    tree.print_tree();
    std::cout << "Traversal has ended. You have reached the Spokane River Lower Falls Dam!\n";

    std::cout << "Would you like to add a node of your own? (y/n)" << std::endl;
    char response;
    std::cin >> response;
    if(response == 'y'){
        std::string name;
        int length;
        std::cout << "What is the name?" << std::endl;
        std::cin >> name;
        std::cout << "What is the length from the dam? (miles)" << std::endl;
        std::cin >> length;
        tree.insert(name, length);
        std::cout << "You inserted " << name << " with a length of " << length << " into the tree." << std::endl;
        tree.print_tree();
    } else {
        std::cout << "Lame... :(" << std:: endl;
    }

    //std::cout << "Tree depth: " << tree.calculate_depth() << std::endl;



    return 0;
}