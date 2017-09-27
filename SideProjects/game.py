class Player(object):
    """
    @Class: Player
    @Methods: __init__, __str__,level,levelUP.
    @Attributes:
    @Description: Initializes the player with his attributes.
    """
    def __init__(self, name, job):
        self.player = name
        self.exp = 456123
        self.strength = Jobs(job).strength
        self.con = Jobs(job).con
        self.dex = Jobs(job).dex
        self.intel = Jobs(job).intel
        self.wil = Jobs(job).wil
        self.skill = Jobs(job).skill
        self.lvl = 1
        self.job = job

    def __str__(self):
        """
        @Method: __str__
        @Description: Defines how the players stats are displayed if printed.
        """
        return ("Name %s, Class %s, XP %d, STR %d, Con %d, Dex %d, Int %d, Wil %d, Skill %d, LVL %d"
                % (self.player, self.job, self.exp, self.strength, self.con, self.dex, self.intel,
                   self.wil, self.skill, self.lvl))

    def level(self):
        """
        @Method: level
        @Descritpion: Takes an exp value and checks it towards to the limits of each level to
        determine if the player has leveled up or not.
        """
        levels = []
        for i in range(0, 50):
            if i is 0:
                levels.append(i * 100000)
            else:
                levels.append((i * 100000) + levels[i - 1])
        return levels

    def levelUp(self):
        """
        @Method: levelUP
        @Description: determines if player has reached an exp value neccessary and sufficient for
        leveling up
        """
        lv = self.level()
        for i in range(0, self.lvl):
            del lv[0]
        if self.exp > lv[0]:
            self.lvl += 1
            self.strength *= 1.5
            self.con *= 1.5
            self.dex *= 1.5
            self.intel *= 1.5
            self.wil *= 1.5
            self.skill *= 1.5
            self.levelUp()

###############################################################################
###############################################################################
class Jobs(Player):
    """
    Class: Jobs
    Description: sets the base stats for the players character
    """
    def __init__(self, job):
        if job is "warrior":
            self.strength = 10
            self.con = 10
            self.dex = 5
            self.intel = 1
            self.wil = 5
            self.skill = 1

        if job == "archer":
            self.strength = 5
            self.con = 5
            self.dex = 10
            self.intel = 1
            self.wil = 1
            self.skill = 1

        if job == "wizard":
            self.strength = 1
            self.con = 5
            self.dex = 1
            self.intel = 10
            self.wil = 10
            self.skill = 1

###############################################################################
###############################################################################

if __name__ == '__main__':
    rick = Player("Jincoperson", "warrior")
    rick.levelUp()
    print(rick)
    nick = Player("Vamilya", "archer")
    nick.levelUp()
    print(nick)
    vick = Player("Shina_Tomi", "wizard")
    vick.levelUp()
    print(vick)
