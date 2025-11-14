function addsecretdiv(){
	const scdiv = document.getElementById('secretdiv');
	var newDiv = document.createElement('div');

	newDiv.innerHTML = '\
            <div class="bg-white rounded-2xl p-8 card-hover" id="secretpass">\
            	<h3>SecretText</h3>\
            </div>';
	newDiv.setAttribute('id', 'newDiv');

	scdiv.appendChild(newDiv);
	document.getElementById('inputpass').remove();
}