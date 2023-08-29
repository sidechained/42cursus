#include "ASpell.hpp"
#include "ATarget.hpp"
#include "Fwoosh.hpp"
#include "Fireball.hpp"
#include "Polymorph.hpp"
#include "Dummy.hpp"
#include "BrickWall.hpp"
#include "Warlock.hpp"
#include "TargetGenerator.hpp"

// clear; c++ -Wall -Werror -Wextra ASpell.cpp  ATarget.cpp  BrickWall.cpp  Dummy.cpp  Fireball.cpp  Fwoosh.cpp  Polymorph.cpp  SpellBook.cpp  TargetGenerator.cpp Warlock.cpp main.cpp

int main()
{
  Warlock richard("Richard", "foo");
  richard.setTitle("Hello, I'm Richard the Warlock!");
  BrickWall model1;

  Polymorph* polymorph = new Polymorph();
  TargetGenerator tarGen;

  tarGen.learnTargetType(&model1);
  richard.learnSpell(polymorph);

  Fireball* fireball = new Fireball();

  richard.learnSpell(fireball);

  ATarget* wall = tarGen.createTarget("Inconspicuous Red-brick Wall");

  richard.introduce();
  richard.launchSpell("Polymorph", *wall);
  richard.launchSpell("Fireball", *wall);
}
// my output

// Richard: This looks like another boring day.$
// Richard: I am Richard, the Titled!$
// Target Practice Dummy has been fwooshed!$ 
// Richard: My job here is done!$

// expected output

// Richard: This looks like another boring day.$
// Richard: I am Richard, the Titled!$
// Target Practice Dummy has been fwooshed!$
// Richard: My job here is done!$
