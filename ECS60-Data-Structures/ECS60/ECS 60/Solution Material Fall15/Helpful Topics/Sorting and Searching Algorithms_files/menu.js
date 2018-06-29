// Based on Slashdot menu: http://www.dynamicdrive.com/dynamicindex1/slashdot.htm
function SDMenu(id) {
	if (!document.getElementById || !document.getElementsByTagName)
		return false;
	this.menu = document.getElementById(id);
	this.submenus = this.menu.getElementsByTagName("div");
	this.speed = 100; // 3 originally
	this.oneSmOnly = false;
	this.initCollapseAll = false;
}
SDMenu.prototype.init = function() {
	var mainInstance = this;
	for (var i = 0; i < this.submenus.length; i++)
		this.submenus[i].getElementsByTagName("span")[0].onclick = function() {
			mainInstance.toggleMenu(this.parentNode);
		};
		
	var links = this.menu.getElementsByTagName("a");
	var loc = document.location.href;
	var pos = loc.indexOf('#');
	if (pos != -1)
		loc = loc.slice(0, pos);
		
	var found = false;
	for (var i = 0; i < links.length; i++) {
		if (links[i].href == loc) {
			links[i].className = "current";
			found = true;
			break;
		}
	}
	if (!found) links[0].className = "current";
	
	var regex = new RegExp("sdmenu_" + encodeURIComponent(this.menu.id) + "=([01]+)");
	var match = regex.exec(document.cookie);
	if (match) {
		var states = match[1].split("");
		foundSub = false;
		for (var i = 0; i < states.length; i++) {
			if (states[i] == 0) {
				this.submenus[i].className = "collapsed";
				if (foundSub) continue;
				
				var linksSub = this.submenus[i].getElementsByTagName("a");
				for (var j = 0; j < linksSub.length; j++) {
					if (linksSub[j].className == "current") {
						// trying to close submenu that contains item
						this.submenus[i].className = "";
						foundSub = true;
						break;
					}
				}
			} else {
				this.submenus[i].className = "";
			}
		}
		if (foundSub) mainInstance.memorize();
	} else {
		if (this.initCollapseAll || this.oneSmOnly) {
			this.collapseAll();
		}
	}
};
SDMenu.prototype.toggleMenu = function(submenu) {
	if (submenu.className == "collapsed")
		this.expandMenu(submenu);
	else
		this.collapseMenu(submenu);
};
SDMenu.prototype.expandMenu = function(submenu) {
	var fullHeight = submenu.getElementsByTagName("span")[0].offsetHeight;
	var links = submenu.getElementsByTagName("a");
	for (var i = 0; i < links.length; i++)
		fullHeight += links[i].offsetHeight;
	var moveBy = Math.round(this.speed * links.length);
	var mainInstance = this;
	var intId = setInterval(function() {
		var curHeight = submenu.offsetHeight;
		var newHeight = curHeight + moveBy;
		if (newHeight < fullHeight)
			submenu.style.height = newHeight + "px";
		else {
			clearInterval(intId);
			submenu.style.height = "";
			submenu.className = "";
			mainInstance.memorize();
		}
	}, 30);
	this.collapseOthers(submenu);
};
SDMenu.prototype.collapseMenu = function(submenu) {
	// force main menu to stay open
	if (submenu == this.submenus[0]) return;
	
	// force menu with selection to stay open
	var links = submenu.getElementsByTagName("a");
	for (var i = 0; i < links.length; i++)
		if (links[i].className == "current") return;
	
	var minHeight = submenu.getElementsByTagName("span")[0].offsetHeight;
	var moveBy = Math.round(this.speed * submenu.getElementsByTagName("a").length);
	var mainInstance = this;
	var intId = setInterval(function() {
		var curHeight = submenu.offsetHeight;
		var newHeight = curHeight - moveBy;
		if (newHeight > minHeight)
			submenu.style.height = newHeight + "px";
		else {
			clearInterval(intId);
			submenu.style.height = "";
			submenu.className = "collapsed";
			mainInstance.memorize();
		}
	}, 30);
};
SDMenu.prototype.collapseOthers = function(submenu) {
	if (this.oneSmOnly) {
		for (var i = 0; i < this.submenus.length; i++)
			if (this.submenus[i] != submenu && this.submenus[i].className != "collapsed")
				this.collapseMenu(this.submenus[i]);
	}
};
SDMenu.prototype.expandAll = function() {
	var oldOneSmOnly = this.oneSmOnly;
	this.oneSmOnly = false;
	for (var i = 0; i < this.submenus.length; i++)
		if (this.submenus[i].className == "collapsed")
			this.expandMenu(this.submenus[i]);
	this.oneSmOnly = oldOneSmOnly;
};
SDMenu.prototype.collapseAll = function() {
	for (var i = 0; i < this.submenus.length; i++)
		if (this.submenus[i].className != "collapsed")
			this.collapseMenu(this.submenus[i]);
};
SDMenu.prototype.memorize = function() {
	var states = new Array();
	for (var i = 0; i < this.submenus.length; i++)
		states.push(this.submenus[i].className == "collapsed" ? 0 : 1);
	var d = new Date();
	d.setTime(d.getTime() + (30 * 24 * 60 * 60 * 1000));
	document.cookie = "sdmenu_" + encodeURIComponent(this.menu.id) + "=" + states.join("") + "; expires=" + d.toGMTString() + "; path=/";
};