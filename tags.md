---
layout: page
title: "tags"
permalink: /tag/
main_nav: true
---
<!-- 
<div id='tag_cloud' class="tags">
    {% for tag in site.tags %}
    <a href="#{{ tag[0] }}" title="{{ tag[0] }}" rel="{{ tag[1].size }}">{{ tag[0] }}</a>
    {% endfor %}
</div>

{% assign tags = site.tags | sort %}
{% for tag in site.tags %}
<h2>{{ tag[0]}} </h2>
<ul>
    {% for post in tag[1] %}
    <li>
        <a href="{{ post.url | relative_url }}">{{ post.title }}</a>
    </li>
    {% endfor %}
</ul>
{% endfor %} -->
<!-- <button type="button" onclick="location.href='/'"> wtf </button> -->
<!-- Page Header -->
<header class="intro-header" style="background-image: url('{{ site.baseurl }}/{% if page.header-img %}{{ page.header-img }}{% else %}{{ site.header-img }}{% endif %}')">
    <div class="container">
        <div class="row">
            <div class="col-lg-8 col-lg-offset-2 col-md-10 col-md-offset-1">
                <div class="site-heading" id="tag-heading">
                    <!-- <h1>{% if page.title %}{{ page.title }}{% else %}{{ site.title }}{% endif %}</h1>
                    <span class="subheading">{{ page.description }}</span> -->
                </div>
            </div>
        </div>
    </div>
</header>

<!-- Main Content -->
<div class="container">
	<div class="row">
		<div class="col-lg-8 col-lg-offset-2 col-md-10 col-md-offset-1">
            <!-- 标签云 -->
			<div id='{{tag_cloud | slugify}}' class="tags"  style="text-align: center">
				{% for tag in site.tags %}
				<button type="button" onclick="location.href='#{{ tag[0] }}'" title="{{ tag[0] }}" rel="{{ tag[1].size }}">{{ tag[0] }}</button>
				{% endfor %}
				<hr>
			</div>
            <!-- 标签列表 -->
			{% for tag in site.tags %}
			<div class="one-tag-list">
			  	<span class="fa fa-tag listing-separator" id="{{ tag[0] }}">
                    <span class="tag-text" style="font-size:32px; color: #7f8c8d">{{ tag[0]}}</span>
					<hr style="border: 1px solid #2980b9">
                </span>
				{% for post in tag[1] %}
				  <!-- <li class="listing-item">
				  <time datetime="{{ post.date | date:"%Y-%m-%d" }}">{{ post.date | date:"%Y-%m-%d" }}</time>
				  <a href="{{ post.url }}" title="{{ post.title }}">{{ post.title }}</a>
				  </li> -->
				 <div class="post-preview">
				    <a href="{{ post.url | prepend: site.baseurl }}">
				        <h2 >
                            {{ post.title }}
				        </h2>
				        {% if post.subtitle %}
				        <h3 class="post-subtitle">
				            {{ post.subtitle }}
				        </h3>
				        {% endif %}
				    </a>
				    <!-- <p class="post-meta">{{ post.date | date:"%Y-%m-%d" }}</p> -->
				</div>
				<hr>
				{% endfor %}
			</div>
			{% endfor %}

		</div>
	</div>
</div>