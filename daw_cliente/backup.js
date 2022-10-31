/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

 var inputs = readline().split(' ');
 const baseX = parseInt(inputs[0]); // The corner of the map representing your base
 const baseY = parseInt(inputs[1]);
 const heroesPerPlayer = parseInt(readline()); // Always 3
 
 
 const baseStats = {
	 hp: 0,
	 mana: 0
 }
 // FUNCIONES
 const getThreats = (enemys) => enemys.filter((monst) => monst.threatFor == 1);
 const getTrajectory = (enemys) => enemys.filter((monst) => monst.nearBase == 1);
 const getDistance = (x1, y1, x2, y2) => Math.sqrt(Math.pow((x2 - x1), 2) + Math.pow((y2 - y1), 2));
 const getDistanceBase = (x, y) => getDistance(baseX, baseY, x, y);
 const getDistanceEnemy = (cx, cy, ex, ey) => getDistance(ex, ey, cx, cy);
 
 const getNearest = (enemys) => {
	 let target = undefined;
	 enemys.forEach((enemy, i) => {
		 if (!target || (getDistanceBase(enemy.x, enemy.y) < target.distance)) {
			 target = {
				 i: i,
				 distance: getDistanceBase(enemy.x, enemy.y),
			 }
		 }
	 })
	 return target.i;
 }
 
 const getNearestRival = (hero, enemys) => {
	 let target = undefined;
	 enemys.forEach((enemy, i) => {
		 if (!target || (getDistanceEnemy(hero.x, hero.y, enemy.x, enemy.y) < target.distance)) {
			 target = {
				 i: i,
				 distance: getDistanceEnemy(hero.x, hero.y, enemy.x, enemy.y),
			 }
		 }
	 })
	 return target.i;
 }
 // ACCIONES
 const move = (x, y, msg = "MOVING") => console.log(`MOVE ${x} ${y} ${msg}`);
 const wait = () => console.log("WAIT WAITING");
 const spellWind = (x, y, msg = "WIND") => console.log(`SPELL WIND ${x} ${y} ${msg}`);
 const spellShield = (id, msg = "SHIELD") => console.log(`SPELL SHIELD ${id} ${msg}`);
 const spellControl = (id, x, y, msg = "CONTROL") => console.log(`SPELL CONTROL ${id} ${x} ${y} ${msg}`);
 
 
 
 // game loop
 while (true) {
	 for (let i = 0; i < 2; i++) {
		 var inputs = readline().split(' ');
		 const health = parseInt(inputs[0]); // Your base health
		 const mana = parseInt(inputs[1]); // Ignore in the first league; Spend ten mana to cast a spell
		 baseStats.hp = health;
		 baseStats.mana = mana;
	 }
	 const entityCount = parseInt(readline()); // Amount of heros and monsters you can see
 
 
	 const enemys = [];
	 const rivals = [];
	 const heros = [];
 
	 for (let i = 0; i < entityCount; i++) {
		 var inputs = readline().split(' ');
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
		 if (type == 0) {
			 enemys.push({
				 id,
				 type,
				 x,
				 y,
				 health,
				 vx,
				 vy,
				 nearBase,
				 threatFor
			 })
		 } else if (type == 2) {
			 rivals.push({
				 id,
				 type,
				 x,
				 y,
				 health,
				 vx,
				 vy,
				 nearBase,
				 threatFor
			 })
		 }
		 else if (type == 1) {
			 heros.push({
				 id,
				 type,
				 x,
				 y,
				 health,
				 vx,
				 vy,
				 nearBase,
				 threatFor
			 })
		 }
	 }
 
 
	 // ACCIONES
	 const actionThreats = () => {
		 //BUSCAR AMENAZAS
		 const threats = getThreats(enemys);
		 if (threats.length > 0) {
			 const p = getNearest(threats);
			 const x = threats[p].x + threats[p].vx;
			 const y = threats[p].y + threats[p].vy;
			 move(x, y);
			 return true;
		 } else return false;
	 }
	 const actionTrajectory = () => {
		 // BUSCAR MONSTERS EN TRAYECTORIA
		 const trajectory = getTrajectory(enemys);
		 if (trajectory.length == 1) {
			 const p = getNearest(trajectory);
			 const x = trajectory[p].x + trajectory[p].vx;
			 const y = trajectory[p].y + trajectory[p].vy;
			 move(x, y);
			 return true;
		 } else if (trajectory.length > 1){
			 const p = getNearest(trajectory);
			 const x = trajectory[p].x + trajectory[p].vx;
			 const y = trajectory[p].y + trajectory[p].vy;
			 if (baseX == 0) spellControl(trajectory[p].id, 17630, 9000);
			 else spellControl(trajectory[p].id, 0, 0);
		 }else return false;
	 }
	 const actionPushRivals = (i) => {
		 const p = getNearestRival(heros[i], enemys);
		 const x = rivals[p].x + rivals[p].vx;
		 const y = rivals[p].y + enemys[p].vy;
		 if (baseStats.mana > 10 && getDistanceEnemy(heros[i].x, heros[i].y, rivals[p].x, rivals[p].y) < 1280) spellWind(-x, -y);
		 else move(x, y);
	 }
 
	 const actionMoveRandom = (hero) => {
		 const limit = 1000;
		 move(Math.floor(Math.random(hero.x) * limit), Math.floor(Math.random(hero.y) * limit))
	 }
 
	 const exploreNearBase = (x, y) => {
		 const dist = 1000;
		 move(Math.floor(x + Math.random() * dist), y + Math.floor(Math.random() * dist))
	 }
 
	 const exploreAwayBase = (x, y) => {
		 const dist = 2000;
		 move(Math.floor(x + Math.random() * dist), y + Math.floor(Math.random() * dist))
	 }
	 
 
	 for (let i = 0; i < heroesPerPlayer; i++) {
 
		 // Write an action using console.log()
		 // To debug: console.error('Debug messages...');
 
		 try {
			 // 0 - DEFENSOR
			 // 1 - INTERCEPTOR
			 // 2 - PUSHER
 
			 if (i == 0) {
				 //BUSCAR AMENAZAS
				 if (!actionThreats()) exploreNearBase(heros[i].x, heros[i].y)
			 }
			 else if (i == 1) {
				 // BUSCAR MONSTERS EN TRAYECTORIA
				 if (!actionThreats()) exploreAwayBase(heros[i].x, heros[i].y)
			 }
			 else if (i == 2) {
				 if (actionThreats()) {
					
				 } else if (rivals.length > 0) {
					 actionPushRivals(i);
				 } else {
					 //actionMoveRandom(heros[i]);
					 if (!actionTrajectory()) actionMoveRandom(heros[i])
				 }
			 } else {
				 wait();
			 }
 
		 } catch (e) {
			 console.error(e)
			 wait();
		 }
 
	 }
 }
 