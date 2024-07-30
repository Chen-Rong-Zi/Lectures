// pragma once

const bool DEBUG = 1;
# include <fstream>
# include <iostream>
# include <string>
# include <stdexcept>
# include <memory>
# include <map>
# include <utility>
# include <generator>
# include <chrono>

# include <nlohmann/json.hpp>
# include <httpserver.hpp>

# include <self/functional.h>

using json = nlohmann::json;
using namespace util;
using namespace fp;

class GameOverException;
class AntsWinException;
class AntsLoseException;
class Place;
class Insect;
class Ant;
class HarvesterAnt;
class ThrowerAnt;
class ShortThrower;
class LongThrower;
class FireAnt;
class WallAnt;
class HungryAnt;
class ContainerAnt;
class BodyguardAnt;
class TankAnt;
class Water;
class ScubaThrower;
class QueenAnt;
class AntRemover;
class Bee;
class Wasp;
class NinjaBee;
class Hive;
class WetLayoutManager;
class DryLayoutManager;
class DeployAntStrategy;
class GameState;
class AntHomeBase;
class AssaultPlan;
class InsectFactory;
class Gui;
class InsectDeadBehavior;
class HttpServer;
class BeeToBeMade;
class WaspToBeMade;
class NinjaTobeMade;



class GameOverException : public std::exception {
    /* Base game over Exception. */
    // std::cout << "GameOverException" << std::endl;
};


class AntsWinException : public GameOverException {
    /* Exception to signal that the ants win.   */
    // std::cout << "AntsWinException" << std::endl;
    // std::cout << "AntsWinException" << std::endl;
};


class AntsLoseException : public GameOverException {
    /*  Exception to signal that the ants lose.  */
    // std::cout << "AntsLoseException" << std::endl;
};

class AddInsectError {
    /*  Exception to signal that the ants lose.  */
    // std::cout << "AntsLoseException" << std::endl;
};
void ants_lose();
void ants_win();
std::shared_ptr<Gui> start_with_option();

long long timestamp() {
    auto now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
    return milliseconds;
}


class Place : public std::enable_shared_from_this<Place> {
    /** A Place holds insects and has an exit to another Place.
     * */
public:
    virtual bool is_hive() {
        return false;
    }
    List<std::shared_ptr<Bee>> bees = List<std::shared_ptr<Bee>>();
    std::shared_ptr<Ant> ant;        // shared_ptr' s empty constructor stores nullptr, which can represent None
    std::shared_ptr<Place> exit;
    std::shared_ptr<Place> entrance;
    std::string name;
    Place() = default;
    Place(std::string name, std::shared_ptr<Place> exit = nullptr):
        name(name),
        exit(exit)
    {
        /** Create a Place with the given NAME and EXIT.
         * name -- A string; the name of this Place.
         * exit -- The Place reached by exiting this Place (may be None).
        */
    };

    Place(std::shared_ptr<Place> other) {
        this->exit     = other->exit;
        this->ant      = other->ant;
        this->entrance = other->entrance;
        this->name     = other->name;
    };
    void __init__();
    virtual void add_insect(std::shared_ptr<Insect> insect);
    virtual void remove_insect(std::shared_ptr<Insect> insect);
    virtual std::string to_string();
};

class InsectDeadBehavior {
private:
    std::shared_ptr<Gui> gui;
public:
    InsectDeadBehavior()
    {};

    InsectDeadBehavior(std::shared_ptr<Gui> gui):
        gui(gui)
    {};
    void updateGuiState(std::shared_ptr<Insect> insect);
};


class Insect : public std::enable_shared_from_this<Insect> {
/**
 * An Insect, the base class of Ant and Bee, has health and a Place.
 */
public:
    InsectDeadBehavior dead_behavior;
    double damage;
    double health;
    bool is_waterproof = false;
    std::shared_ptr<Place> place;
    Insect():
        health(1),
        place(nullptr),
        damage(0.0)
    {};
    Insect(double health, std::shared_ptr<Place> place = nullptr):
        health(health),
        place(place),
        damage(0)
    {
        /**
         * Create an Insect with a health amount and a starting PLACE.
         */
    }
    Insect(std::shared_ptr<Insect> other) {
        this->health = other->health;
        this->place  = other->place;
    }
    virtual void reduce_health(double amount);
    virtual void action(std::shared_ptr<GameState> gamestate);
    virtual void death_callback();
    virtual void add_to(std::shared_ptr<Place> place);
    virtual void remove_from(std::shared_ptr<Place> place);
    virtual std::string get_name();
};

class Ant : public Insect {
/**An Ant occupies a place and does work for the colony.
 */

public:
    int food_cost = 0;
    bool buffed = false;
    Ant(double health = 3.0):
        Insect(health)
    {
        /** Create an Insect with a HEALTH quantity.
         */
    }
    Ant(std::shared_ptr<Ant> other) {
        this->health = other->health;
    }
    virtual void action(std::shared_ptr<GameState>);
    virtual std::string get_name();
    virtual int get_food_cost();
    virtual bool is_container();
    virtual bool can_contain(std::shared_ptr<Ant> other);
    virtual void remove_ant(std::shared_ptr<Ant> other);
    virtual void remove_from(std::shared_ptr<Place> place);
    std::shared_ptr<Ant> get_self();
    virtual void store_ant(std::shared_ptr<Ant> other);
    void add_to(std::shared_ptr<Place> place);
    void buff();
};


class HarvesterAnt : public Ant {
    /**
     * HarvesterAnt produces 1 additional food per turn for the colony.
     */
public:
    HarvesterAnt():
        Ant()
    {};
    std::string name = "Harvester";
    int food_cost = 2;

    void action(std::shared_ptr<GameState> gamestate);
    std::string get_name();
    int get_food_cost();
};

class ThrowerAnt : public Ant {
public:
    std::string name = "Thrower";
    int min_range = 0;
    int max_range = 2147483647;
    int food_cost = 3;

    ThrowerAnt():
        Ant()
    {
        this->damage = 1;
    }
    std::string get_name();
    std::shared_ptr<Bee> nearest_bee();
    void throw_at(std::shared_ptr<Bee> target);
    void action(std::shared_ptr<GameState> gamestate);
    int get_food_cost();
    virtual int get_max_range() {
        return this->max_range;
    }
    virtual int get_min_range() {
        return this->min_range;
    }
};

std::shared_ptr<Bee> random_bee(List<std::shared_ptr<Bee>> bees);

// ##############
// # Extensions #
// ##############

class ShortThrower : public ThrowerAnt
{
/*  A ThrowerAnt that only throws leaves at Bees at most 3 places away.  */
public:
    ShortThrower():
        ThrowerAnt()
    {};
    std::string name = "Short";
    int max_range = 3;
    int food_cost = 2;
    int get_max_range() {
        return this->max_range;
    }
    int get_min_range() {
        return this->min_range;
    }
    int get_food_cost();
    std::string get_name();
};


class LongThrower : public ThrowerAnt {
    /*  A ThrowerAnt that only throws leaves at Bees at least 5 places away.  */
    std::string name = "Long";
    int min_range = 5;
    int food_cost = 2;
    int get_max_range() {
        return this->max_range;
    }
    int get_min_range() {
        return this->min_range;
    }
    int get_food_cost();
    std::string get_name();
};


class FireAnt : public Ant {
    /* FireAnt cooks any Bee in its Place when it expires.  */
public:
    std::string name = "Fire";
    int damage = 3;
    int food_cost = 5;

    FireAnt(double health = 3):
        Ant(health)
    {};
    void reduce_health(double amount);
    int get_food_cost();
    std::string get_name();
};

class WallAnt : public Ant {
public:
    std::string name = "Wall";
    int food_cost = 4;
    std::string get_name();
    int get_food_cost();
    WallAnt():
        Ant(10)
    {};
};


class HungryAnt : public Ant {
public:
    std::string name           = "Hungry";
    int         food_cost      = 4;
    int         chew_duration  = 3;
    int         chew_countdown = 0;

    HungryAnt():
        Ant(1),
        chew_countdown(0)
    {};
    void action(std::shared_ptr<GameState> gamestate);
    std::string get_name();
    int get_food_cost();
};


class ContainerAnt : public Ant {
    /*  ContainerAnt can share a space with other ants by containing them.  */
public:
    std::shared_ptr<Ant> ant_contained;

    ContainerAnt(std::shared_ptr<Ant> other):
        Ant(other),
        ant_contained(nullptr)
    {};

    ContainerAnt(double health):
        Ant(health),
        ant_contained(nullptr)
    {};
    std::shared_ptr<ContainerAnt> get_self() {
        return std::dynamic_pointer_cast<ContainerAnt>(this->shared_from_this());
    }
    virtual bool is_container();
    void reduce_health(double amount);
    bool can_contain(std::shared_ptr<Ant> other);
    void store_ant(std::shared_ptr<Ant> ant);
    void remove_ant(std::shared_ptr<Ant> ant);
    void remove_from(std::shared_ptr<Place> place);
    virtual void action(std::shared_ptr<GameState> gamestate);
};

class BodyguardAnt : public ContainerAnt {
    /*  BodyguardAnt provides protection to other Ants.  */
public:
    std::string name = "Bodyguard";
    int food_cost = 4;

    BodyguardAnt():
        ContainerAnt(2)
    {};
    int get_food_cost();
    std::string get_name();
};

class TankAnt : public ContainerAnt {
public:
    std::string name = "Tank";
    int food_cost = 6;
    double damage = 1;

    TankAnt():
        ContainerAnt(5)
    {};

    int get_food_cost();
    void action(std::shared_ptr<GameState> gamestate);
    std::string get_name();
};

class Water : public Place {
    /*  Water is a place that can only hold waterproof insects.  */
public:
    Water(std::string name, std::shared_ptr<Place> exit = nullptr):
        Place(name, exit)
    {
    };
    int get_food_cost();
    void add_insect(std::shared_ptr<Insect> insect) {
        /* Add an Insect to this place. If the insect is not waterproof, reduce its health to 0.   */
        Place::add_insect(insect);
        if ( (!insect->is_waterproof) && (insect != nullptr) )
            insect->reduce_health(insect->health);
    }
};

class ScubaThrower : public ThrowerAnt {
public:
    std::string name = "Scuba";
    int food_cost = 6;

    ScubaThrower():
        ThrowerAnt()
    {
        this->is_waterproof = true;
    };
    int get_food_cost();
    std::string get_name();
};

class QueenAnt : public ScubaThrower {
    /*  The Queen of the colony. The game is over if a bee enters her place.  */
public:
    std::string name = "Queen";
    int food_cost = 7;

    QueenAnt(std::shared_ptr<GameState> gamestate);
    List<std::shared_ptr<Ant>> behind_ants(std::shared_ptr<Place> place);
    int get_food_cost();
    std::string get_name();
    void action(std::shared_ptr<GameState> gamestate);
    void reduce_health(double amount);
};


class AntRemover : public Ant {
    /* Allows the player to remove ants from the board in the GUI.   */
public:
    std::string name = "Remover";
    AntRemover():
        Ant(0.0)
    {};
    int get_food_cost();
    std::string get_name();
};


class Bee : public Insect {
    /* A Bee moves from place to place, following exits and stinging ants. */
private:
    std::shared_ptr<Bee> get_self() {
        return std::dynamic_pointer_cast<Bee>(this->shared_from_this());
    }
    bool blocked() {
        print("I am ", this->get_name(), " in ", this->place->to_string(), " and i am blocked: ", this->place->ant != nullptr);
        return this->place->ant != nullptr;
    }
public:
    std::string name = "Bee";
    int damage = 1;
    Bee(double health):
        Insect(health, nullptr)
    {
        this->is_waterproof = true;
    };
    Bee():
        Insect(3, nullptr)
    {};

    void sting(std::shared_ptr<Ant> ant);
    void move_to(std::shared_ptr<Place> place);
    void action(std::shared_ptr<GameState> gamestate);
    void add_to(std::shared_ptr<Place> place);
    void remove_from(std::shared_ptr<Place> place);
    std::string get_name();
};


class Wasp : public Bee {
    /*  Class of Bee that has higher damage.  */
public:
    Wasp(double health):
        Bee(health)
    {};
    Wasp():
        Bee()
    {};
    std::string name = "Wasp";
    int damage = 2;
};


class NinjaBee : public  Bee {
    /*  A Bee that cannot be blocked. Is capable of moving past all defenses to assassinate the Queen.  */
public:
    NinjaBee(double health):
        Bee(health)
    {};
    NinjaBee():
        Bee()
    {};
    std::string name = "NinjaBee";

    bool blocked() {
        return false;
    }
};


class Hive : public Place {
    /**The Place from which the Bees launch their assault.
     *assault_plan -- An AssaultPlan; when & where bees enter the colony.
     */
private:
    std::shared_ptr<Hive> get_self() {
        return std::dynamic_pointer_cast<Hive>(this->shared_from_this());
    }
public:
    std::shared_ptr<AssaultPlan> assault_plan;

    Hive(std::shared_ptr<AssaultPlan> assault_plan);
    void __init__();
    bool is_hive() {
        return true;
    }
    void strategy(std::shared_ptr<GameState> gamestate);
};

class WetLayoutManager : public std::enable_shared_from_this<WetLayoutManager> {
private:
    std::shared_ptr<GameState> gamestate;
public:
    WetLayoutManager():
        gamestate(nullptr)
    {};

    void set_gamestate(std::shared_ptr<GameState> gamestate);
    void register_place(std::shared_ptr<Place> place, bool is_bee_entrance);
    virtual void set_layout(std::shared_ptr<Place> base, int tunnels, int length, int moat_frequency);
};

class DryLayoutManager : public WetLayoutManager {
public:
    DryLayoutManager():
        WetLayoutManager()
    {};
    void set_layout(std::shared_ptr<Place> base, int tunnels, int length, int moat_frequency);
};

class DeployAntStrategy {
private:
    std::shared_ptr<GameState> gamestate;
public:
    void initialize_colony_graphics();
    DeployAntStrategy(std::shared_ptr<GameState> gamestate):
        gamestate(gamestate)
    {};

    std::shared_ptr<GameState> apply();
};

class GameState : public std::enable_shared_from_this<GameState> {
/**
 * An ant collective that manages global game state and simulates time.
 * Attributes:
 * time -- elapsed time
 * food -- the colony's available food total
 * places -- A list of all places in the colony (including a Hive)
 * bee_entrances -- A list of places that bees can enter
 */
private:
    std::shared_ptr<WetLayoutManager> place_manager;
    void ants_action();
    void bees_action();
    std::generator<std::shared_ptr<GameState>> set_game();

public:
    bool has_queen = false;
    int time;
    int food;
    std::shared_ptr<Hive> beehive;
    std::shared_ptr<std::pair<int, int>> dimensions;
    std::shared_ptr<DeployAntStrategy> deploy_ant_strategy;
    List<std::shared_ptr<Bee>> active_bees;

    std::shared_ptr<AntHomeBase> base;
    std::map<std::string, std::shared_ptr<Place>> places;
    List<std::shared_ptr<Place>> bee_entrances;
    std::shared_ptr<Gui> gui;
    std::generator<std::shared_ptr<GameState>> game;

    GameState(std::shared_ptr<Hive> beehive, std::shared_ptr<WetLayoutManager> place_manager, std::shared_ptr<std::pair<int, int>> dimensions, int food = 2):
        time(0),
        food(food),
        beehive(beehive),
        dimensions(dimensions),
        active_bees(List<std::shared_ptr<Bee>>()),
        place_manager(place_manager),
        game(set_game())
    {};

    // load json specified version
    // GameState():
    // {
        // this->beehive = std::make_shared<Hive>(make_normal_assault_plan());
        // this->place_manager = std::make_shared<WetLayoutManager>();
    // };

    void __init__();
    void configure(std::shared_ptr<Hive> beehive, std::shared_ptr<WetLayoutManager> place_manager);
    std::shared_ptr<GameState> simulate();
    std::shared_ptr<Ant> deploy_ant(std::string place_name, std::string ant_type_name);
    void remove_ant(std::string place_name);
    List<std::shared_ptr<Insect>> ants();
    List<std::shared_ptr<Insect>> bees();
    List<std::shared_ptr<Insect>> insects();
    std::string to_string();
};

class AntHomeBase : public Place {
    /*  AntHomeBase at the end of the tunnel, where the queen resides.  */
public:
    AntHomeBase(std::string name):
        Place(name)
    {};
    void add_insect(std::shared_ptr<Insect> insect) {
        /** Add an Insect to this Place.
        * Can't actually add Ants to a AntHomeBase. However, if a Bee attempts to
        * enter the AntHomeBase, a AntsLoseException is raised, signaling the end
        * of a game.*/
        // assert isinstance(insect, Bee), "Cannot add {0} to AntHomeBase";
        throw AntsLoseException();
    }
};


// #################
// # Assault Plans #
// #################


class AssaultPlan : public std::enable_shared_from_this<AssaultPlan> {
    /*The Bees' plan of attack for the colony.  Attacks come in timed waves.

    * An AssaultPlan is a dictionary from times (int) to waves (list of Bees).

    * AssaultPlan().add_wave(4, 2)
    * {4: [Bee(3, None), Bee(3, None)]}
    */
public:
    std::map<int, List<std::shared_ptr<Bee>>> plan;
    AssaultPlan():
        plan(std::map<int, List<std::shared_ptr<Bee>>>())
    {};
    std::map<int, List<std::shared_ptr<Bee>>> add_wave(std::string bee_name, double bee_health, int time, int count);
    List<std::shared_ptr<Bee>> all_bees();
    List<std::shared_ptr<Bee>> get(int time);
};

std::shared_ptr<AssaultPlan> make_test_assault_plan();
std::shared_ptr<AssaultPlan> make_easy_assault_plan();
std::shared_ptr<AssaultPlan> make_normal_assault_plan();
std::shared_ptr<AssaultPlan> make_hard_assault_plan();
std::shared_ptr<AssaultPlan> make_extra_hard_assault_plan();

class InsectFactory {
public:
    static std::map<std::string, int> cost_map;
    static std::shared_ptr<Ant> newAnt(std::string type_name, std::shared_ptr<GameState> gamestate);
    static std::shared_ptr<Bee> newBee(std::string type_name, double health);
};

std::map<std::string, int> InsectFactory::cost_map = {
    {"Harvester", 2},
    {"Thrower",   3},
    {"Short",     2},
    {"Long",      2},
    {"Hungry",    3},
    // {"Slow",      4},
    {"Wall",      4},
    {"Bodyguard", 4},
    {"Hungry",    4},
    {"Fire",      5},
    {"Tank",      6},
    {"Scuba",     6},
    {"Queen",     7},
    // {"Remover",   0},
    {"Bee",       0},
    {"Wasp",      0},
    {"NinjaBee",  0}
};


class Gui : public std::enable_shared_from_this<Gui> {
public:
constexpr static std::string ASSETS_DIR = "assets/";
constexpr static std::string INSECT_DIR = "insects/";
constexpr static int STRATEGY_SECONDS = 3;
static std::map<std::string, std::string> INSECT_FILES;

private:
    void clean_state();
    void set_place_name_by_row_col(std::string row, std::string col, std::string name);
    void set_place_by_name(std::string name);

public:
    bool initialized = false;
    bool active;
    bool gameOver;
    std::shared_ptr<GameState> gamestate;
    int currentBeeId;
    int currentInsectId;
    List<int> insects;
    List<int> bees;
    List<int> deadbees;
    List<int> deadinsects;
    std::map<std::shared_ptr<Insect>, int> insectToId;
    std::map<std::shared_ptr<Bee>,    int> beeToId;
    std::map<int,                     std::string> beeLocations;
    json webstate = R"({"time" : 0})"_json;

    Gui();
    Gui(std::shared_ptr<GameState> gamestate);

    void new_game();
    void kill();
    std::string start_game();
    std::string get_insect_img_file(std::string name);
    std::string getState(long long);
    std::string get_place_row(std::string name);
    std::string get_place_column(std::string name);
    void _init_places(std::shared_ptr<GameState> gamestate);
    void __init__();
    void update_food();
    void _update_control_panel(std::shared_ptr<GameState> gamestate);
    json deploy_ant(json data);
    template <typename T>
    void saveState(std::string key, T val);
    json exit_game(json data);
};

std::map<std::string, std::string> Gui::INSECT_FILES = {
    // {"Worker",       Gui::ASSETS_DIR + Gui::INSECT_DIR + "ant_harvester.gif"},
    {"Harvester",    Gui::ASSETS_DIR + Gui::INSECT_DIR + "ant_harvester.gif"},
    {"Thrower",      Gui::ASSETS_DIR + Gui::INSECT_DIR + "ant_thrower.gif"},
    {"Long",         Gui::ASSETS_DIR + Gui::INSECT_DIR + "ant_longthrower.gif"},
    {"Short",        Gui::ASSETS_DIR + Gui::INSECT_DIR + "ant_shortthrower.gif"},
    // {"Slow",         Gui::ASSETS_DIR + Gui::INSECT_DIR + "ant_slow.gif"},
    {"Wall",         Gui::ASSETS_DIR + Gui::INSECT_DIR + "ant_wall.gif"},
    {"Bodyguard",    Gui::ASSETS_DIR + Gui::INSECT_DIR + "ant_bodyguard.gif"},
    {"Fire",         Gui::ASSETS_DIR + Gui::INSECT_DIR + "ant_fire.gif"},
    {"Tank",         Gui::ASSETS_DIR + Gui::INSECT_DIR + "ant_tank.gif"},
    {"Scuba",        Gui::ASSETS_DIR + Gui::INSECT_DIR + "ant_scary.gif"},
    {"Hungry",       Gui::ASSETS_DIR + Gui::INSECT_DIR + "ant_hungry.gif"},
    {"Queen",        Gui::ASSETS_DIR + Gui::INSECT_DIR + "ant_queen.gif"},
    // {"Scary",        Gui::ASSETS_DIR + Gui::INSECT_DIR + "ant_scary.gif"},
    // {"Laser",        Gui::ASSETS_DIR + Gui::INSECT_DIR + "ant_laser.gif"},
    // {"Ninja",        Gui::ASSETS_DIR + Gui::INSECT_DIR + "ant_ninja.gif"},
    // {"Wasp",         "imag/wasp.gif"},
    // {"Bee",          Gui::ASSETS_DIR + Gui::INSECT_DIR + "bee.gif"},
    {"Scuba", Gui::ASSETS_DIR + Gui::INSECT_DIR + "ant_scuba.gif"}
    // {"Remover",      Gui::ASSETS_DIR + Gui::INSECT_DIR + "remove.png"}
};

class HttpServer {
private:
    static json parse_web_data(std::string content) {
        if ( DEBUG )print("in parse_web_data");
        if ( content.find("&") == std::string::npos ) {
            return json::parse(content);
        }

        json data = R"({})"_json;
        auto tokens = split(content, "&");
        auto key_val = map(tokens, [=] (auto expr) {
                return split(expr, "=");
            });
        for (auto lst : key_val ) {
            data[lst.car_n(0)] = lst.car_n(1);
        }
        // print("parse for_each data = ", data);
        return data;
    }
    static std::string save_state(std::shared_ptr<Gui> gui, std::string content) {
        if ( !gui->active )
            return "{\"status\": \"end\"}";

        std::ifstream f("backup.json");
        json data = json::parse(content);
        // gui->load_game(data);
        return data.dump();
    }

    static std::string load_state(std::shared_ptr<Gui> gui, std::string data) {
        if ( !gui->active )
            return "{\"status\": \"end\"}";
        std::string response = gui->getState(timestamp());

        std::ofstream file("backup.json");
        if (file.is_open()) {
            file << response;
            file.close();
            std::cout << "JSON data saved to backup.json" << std::endl;
        } else {
            std::cerr << "Failed to open file for writing" << std::endl;
        }
        return response;
    }

    static std::string get_state(std::shared_ptr<Gui> gui, std::string data) {
        if ( !gui->active )
            return "{\"status\": \"end\"}";
        std::string response = gui->getState(timestamp());
        return response;
    }

    static std::string start_game(std::shared_ptr<Gui> gui, std::string data) {
        if ( DEBUG )print("in start_game handler");
        if ( DEBUG )print("pass getcontent");
        std::string response =  gui->start_game();
        if ( DEBUG )print("pass start_game");
        return response;
    }

    static std::string exit_game(std::shared_ptr<Gui> gui, std::string data) {
        if ( DEBUG )print("in exit game");
        std::string response =  gui->exit_game(json::parse(data));
        if ( DEBUG )print("pass exit game");
        return response;
    }

    static std::string deploy_ant(std::shared_ptr<Gui> gui, std::string data) {
        if ( !gui->active )
            return "{\"status\": \"end\"}";
        if ( DEBUG )print("in deploy_ant");
        json response = gui->deploy_ant(HttpServer::parse_web_data(data));
        return response.dump();
    }

    class RoutineRequest : public httpserver::http_resource {
    public:
        HttpServer *server;
        RoutineRequest(HttpServer *server):
            server(server)
        {};
        std::shared_ptr<httpserver::http_response> render(const httpserver::http_request& request) {
            std::string content = std::string(request.get_content());
            List<std::string> tokens = split(std::string(request.get_path()), "/");
            for ( auto it : tokens )
            {
                print(it);
            }
            std::string ip      = tokens.car_n(tokens.len() - 1);
            tokens.remove(ip);
            std::string path    = joined(tokens, "/");
            std::string res_str = "";

            print("ip: ", ip);
            print("content: ", content);

            if ( !gui_map.contains(ip) ) {
                auto gui = start_with_option();
                gui->__init__();
                gui_map[ip] = gui;
                return std::shared_ptr<httpserver::http_response>(new httpserver::string_response(""));
            } else if (path.contains("ajax/start/game")) {
                res_str = HttpServer::start_game(gui_map[ip], content);
            } else if (path.contains("ajax/fetch/state")) {
                res_str = HttpServer::get_state(gui_map[ip], content);
            } else if (path.contains("ajax/exit")) {
                res_str = HttpServer::exit_game(gui_map[ip], content);
            } else if (path.contains("ajax/deploy/ant")) {
                res_str = HttpServer::deploy_ant(gui_map[ip], content);
            } else if (path.contains("ajax/save")) {
            } else {
                res_str = "404 NOT FOUND";
            }
            return std::shared_ptr<httpserver::http_response>(new httpserver::string_response(res_str, 200, "application/json"));
        }
    };
public:
    static std::map<std::string, std::shared_ptr<Gui>> gui_map;
    httpserver::webserver ws;
    void start();
    void stop() {
        print("stop server");
        // this->ws.sweet_kill();
    }
    HttpServer();
};
std::map<std::string, std::shared_ptr<Gui>> HttpServer::gui_map = std::map<std::string, std::shared_ptr<Gui>>();


class BeeToBeMade {
public:
    std::shared_ptr<Bee> contstruct(std::shared_ptr<Gui> gui);
};

class WaspToBeMade {
public:
    std::shared_ptr<Wasp> contstruct(std::shared_ptr<Gui> gui);
};

class NinjaTobeMade {
public:
    std::shared_ptr<NinjaBee> contstruct(std::shared_ptr<Gui> gui);
};
