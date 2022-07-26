/** This is what you expect to be done each day
 *
 */
class ChoreTemplate {
    constructor() {
	this.chores = [];
	var ct = localStorage.getItem('chore-template');
	console.log("chore-template is " + ct);
    }
}

/** This is what you effectively did a given day
 *
 */
class Chore {
    constructor(date) {
	this.date = date;
    }
}

//export { ChoreTemplate, Chore};
