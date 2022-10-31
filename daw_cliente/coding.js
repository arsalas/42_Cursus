/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

 var inputs = readline().split(" ");
 const baseX = parseInt(inputs[0]); // The corner of the map representing your base
 const baseY = parseInt(inputs[1]);
 const heroesPerPlayer = parseInt(readline()); // Always 3
 
 const baseStats = {
   hp: 0,
   mana: 0,
 };
 
 // CONSTANTES
 MANA_COST = 10;
 DISTANCE_WIND = 1280;
 // FUNCIONES
 // En trayectoria a tu base
 const getThreats = (enemys) => enemys.filter((monst) => monst.threatFor == 1);
 // En trayectoria a la base enemiga
 const getEnemyThreats = (enemys) =>
   enemys.filter((monst) => monst.threatFor == 2);
 // Estan atacando la base
 const getTrageting = (enemys) => enemys.filter((monst) => monst.nearBase == 1);
 // Obtiene la distancia entre dos puntos
 const getDistance = (x1, y1, x2, y2) =>
   Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2));
 // Obtiene la distancia a la base de una entidad
 const getDistanceBase = (x, y) => getDistance(baseX, baseY, x, y);
 // Obtiene la distancia de un heroe con una entidad
 const getDistanceEnemy = (cx, cy, ex, ey) => getDistance(ex, ey, cx, cy);
 // Obtiene el enemigo mas cerca a la base
 const getNearest = (enemys) => {
   let target = undefined;
   enemys.forEach((enemy, i) => {
     if (!target || getDistanceBase(enemy.x, enemy.y) < target.distance) {
       target = {
         i: i,
         distance: getDistanceBase(enemy.x, enemy.y),
       };
     }
   });
   return target.i;
 };
 // Obtiene el enemigo mas cerca de un heroe
 const getNearestRival = (hero, enemys) => {
   let target = undefined;
   enemys.forEach((enemy, i) => {
     if (
       !target ||
       getDistanceEnemy(hero.x, hero.y, enemy.x, enemy.y) < target.distance
     ) {
       target = {
         i: i,
         distance: getDistanceEnemy(hero.x, hero.y, enemy.x, enemy.y),
       };
     }
   });
   return target.i;
 };
 // ACCIONES BASE
 const move = (x, y, msg = "MOVING") => console.log(`MOVE ${x} ${y} ${msg}`);
 const wait = () => console.log("WAIT WAITING");
 const spellWind = (x, y, msg = "WIND") =>
   console.log(`SPELL WIND ${x} ${y} ${msg}`);
 const spellShield = (id, msg = "SHIELD") =>
   console.log(`SPELL SHIELD ${id} ${msg}`);
 const spellControl = (id, x, y, msg = "CONTROL") =>
   console.log(`SPELL CONTROL ${id} ${x} ${y} ${msg}`);
 
 // ACCIONES
 /**
  * Ataca al enemigo mas cercano a base
  */
 const attackNearestEnemy = (threats) => {
     const p = getNearest(threats);
     const x = threats[p].x + threats[p].vx;
     const y = threats[p].y + threats[p].vy;
     move(x, y);
    };
    /**
     * Envia a los puntos de control
     */
    const goControlPoint = (i) => {
        if (i == 0) move(6600, 6970, "CP 0");
        else if (i == 1) move(8750, 4550, "CP 1");
        else move(11200, 1500, "CP 2");
    };
    
    /**
     * Defiende la base
     */
    const defenseBase = (hero, threats) => {
   const p = getNearest(threats);
   const x = threats[p].x + threats[p].vx;
   const y = threats[p].y + threats[p].vy;
 
   if (
     threats.length > 1 &&
     baseStats.mana > MANA_COST &&
     getDistanceEnemy(hero.x, hero.y, p.x, p.y) < DISTANCE_WIND
   )
     spellWind(-p.x, -p.y);
   else {
     move(x, y);
   }
 };
 
 const controlEnemyNearest = (hero, monsters) => {
   const p = getNearest(monsters);
   const x = monsters[p].x + monsters[p].vx;
   const y = monsters[p].y + monsters[p].vy;
 
   if (
     monsters.length > 1 &&
     baseStats.mana > MANA_COST &&
     getDistanceEnemy(hero.x, hero.y, p.x, p.y) < 2200
   )
     spellControl(-p.x, -p.y);
   else {
     move(x, y);
   }
 };
 
 
 const attackNearestEnemyTrajectory = (monsters) => {
   const p = getNearest(monsters);
   const x = monsters[p].x + monsters[p].vx;
   const y = monsters[p].y + monsters[p].vy;
   move(x, y);
 };
 
 const attackNearestEnemyMonster = (hero, monsters) => {
   const p = getNearestRival(hero, monsters);
   const x = monsters[p].x + monsters[p].vx;
   const y = monsters[p].y + monsters[p].vy;
   move(x, y);
 };
 
 const exploreAwayBase = (x, y) => {
     const dist = 2000;
     move(Math.floor(x + Math.random() * dist), y + Math.floor(Math.random() * dist))
 }
 
 
 // game loop
 while (true) {
   for (let i = 0; i < 2; i++) {
     var inputs = readline().split(" ");
     const health = parseInt(inputs[0]); // Your base health
     const mana = parseInt(inputs[1]); // Ignore in the first league; Spend ten mana to cast a spell
     baseStats.hp = health;
     baseStats.mana = mana;
   }
   const entityCount = parseInt(readline()); // Amount of heros and monsters you can see
 
   const monsters = [];
   const rivals = [];
   const heros = [];
 
   for (let i = 0; i < entityCount; i++) {
     var inputs = readline().split(" ");
     const id = parseInt(inputs[0]); // Unique identifier
     const type = parseInt(inputs[1]); // 0=monster, 1=your hero, 2=opponent hero
     const x = parseInt(inputs[2]); // Position of this entity
     const y = parseInt(inputs[3]);
     const shieldLife = parseInt(inputs[4]); // Ignore for this league; Count down until shield spell fades
     const isControlled = parseInt(inputs[5]); // Ignore for this league; Equals 1 when this entity is under a control spell
     const health = parseInt(inputs[6]); // Remaining health of this monster
     const vx = parseInt(inputs[7]); // Trajectory of this monster
     const vy = parseInt(inputs[8]);
     const nearBase = parseInt(inputs[9]); // 0=monster with no target yet, 1=monster targeting a base
     const threatFor = parseInt(inputs[10]); // Given this monster's trajectory, is it a threat to 1=your base, 2=your opponent's base, 0=neither
     const data = {
       id,
       type,
       x,
       y,
       health,
       vx,
       vy,
       shieldLife,
       isControlled,
       nearBase,
       threatFor,
     };
     if (type == 0) {
       monsters.push(data);
     } else if (type == 2) {
       rivals.push(data);
     } else if (type == 1) {
       heros.push(data);
     }
   }
 
   // ACCIONES
 
   const threats = getTrageting(monsters);
   const trajectory = getThreats(monsters);
 
   for (let i = 0; i < heroesPerPlayer; i++) {
     // Write an action using console.log()
     // To debug: console.error('Debug messages...');
 
     try {
       // DECISIONES
       // Si no hay amenazas ni monsters en trayectoria explorar mapa
       if (monsters.length == 0) {
         goControlPoint(i);
         continue;
       }
       // Comprobar si hay mas amenazas que heroes defendiendo
       if (threats.length > 0 && i == 0) {
         defenseBase(heros[i], threats);
         continue;
       }
       // Si hay enemigos en trayecytoria atacarlos
       if (trajectory.length > i && (i == 0 || i ==1)) {
         attackNearestEnemyTrajectory(trajectory);
         continue;
       }
       // Cambiar trayectoria a enemigos rivales
       if (i == 2)
        attackNearestEnemyMonster(heros[i], monsters);
         //controlEnemyNearest(heros[i], monsters);
       else goControlPoint(1);
     } catch (e) {
       console.error(e);
       wait();
     }
   }
 }
 