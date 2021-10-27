---
layout: page
title: "Study"
permalink: /tag/study/
---

{% for tag in site.tags %}

    {% if tag[0] == "study" %}
<h2> {{tag[0]}} </h2>
<ul>
        {% for post in tag[1] %}
        <li>
        <a href="{{ post.url | relative_url }}">{{ post.title }}
        </a>
        </li>
        {% endfor %}
</ul>
    {% endif %}

{% endfor %}