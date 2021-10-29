---
layout: page
title: About
permalink: /about/
main_nav: true
---

![alt text]({{ site.baseurl }}/assets/mocha_picture.jpg "Profile Picture"){:.profile}

<div style="text-align: center"><h2>This is my dog, called mocha !</h2></div>  
{% include page_divider.html %}

  
<p style="font-size:24px">Hi, this is <b><em>egyeom</em></b>'s blog !</p>

This site is a blog to review and not forget what I have learned.

I'm interested in below
---
---
<ul style="font-size:20px">
    <li>C++/Python</li>
    <li>Embedded System</li>
    <li>Game Programming</li>
    <li>Windows App</li>
</ul>
---

So I want to know and talk with who is interested in the above things in list like me!

Please Contact me below ! 

<ul class="social-media-list">
        <li>
          <a href="mailto:{{ site.email }}">
            <i class="fa fa-envelope-o"></i>
            <span class="username">{{ site.email }}</span>
          </a>
        </li>

        {% for social in site.social %}
          {% if social.url != "" %}
          <li>
            <a href="{{ social.url }}" title="{{ social.desc }}">
              <i class="fa fa-{{ social.icon }}"></i>
              <span class="username">{% if social.username %}{{ social.username }}{% else %}{{ social.name }}{% endif %}</span>
            </a>
          </li>
          {% endif %}
        {% endfor %}
</ul>
------


This Blog theme is Centrarium. Centrarium is a custom theme for Jekyll, made by [Ben Centra][bencentra] for his own blog. He'd be humbled if you liked it enough to use it as well! Installation and configuration instructions can be found in the [GitHub repository](https://github.com/bencentra/centrarium).

