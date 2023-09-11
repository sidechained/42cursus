# Configuration File

• The first server for a host:port will be the default for this host:port (that means it will answer to all the requests that don’t belong to an other server).
• Setup routes with one or multiple of the following rules/configuration (routes wont be using regexp):
-  Define a list of accepted HTTP methods for the route.
-  Define a directory or a file from where the file should be searched (for example, if url /kapouet is rooted to /tmp/www, url /kapouet/pouic/toto/pouet is /tmp/www/pouic/toto/pouet).
-  Turn on or off directory listing.
-  Set a default file to answer if the request is a directory.
-  Execute CGI based on certain file extension (for example .php).

## Example 'server' section of NGINX configuration file that meets most of our requirements

server {
    listen 80;  # Define the port (e.g., 80)
    server_name example.com;  # Set the server_name (optional)

    # Set the root directory for this server block
    root /var/www/html;

    # Default page for directory requests
    index index.html;

    # Define error pages
    error_page 404 /404.html;
    error_page 500 502 503 504 /50x.html;

    # Limit client body size to 10MB
    client_max_body_size 10M;

    # Route configuration for a specific location
    location /kapouet {
        # Define accepted HTTP methods
        if ($request_method !~ ^(GET|POST)$) {
            return 405;
        }

        # HTTP redirection example
        # rewrite ^/kapouet/(.*)$ https://example.com/$1 permanent;

        # Set the directory where files should be searched
        alias /tmp/www;

        # Disable directory listing
        autoindex off;

        # Set a default file for directory requests
        index index.html;

        # Execute PHP files if present
        location ~ \.php$ {
            include fastcgi_params;
            fastcgi_pass unix:/var/run/php-fpm.sock;
            fastcgi_param SCRIPT_FILENAME $document_root$fastcgi_script_name;
        }

        # Handle file uploads (customize the path as needed)
        location /upload {
            client_max_body_size 10M;
            upload_store /var/www/uploads;
            upload_pass /upload;
            upload_set_form_field $upload_field_name.name "$upload_file_name";
            upload_set_form_field $upload_field_name.content_type "$upload_content_type";
            upload_set_form_field $upload_field_name.path "$upload_tmp_path";
            upload_aggregate_form_field "$upload_field_name.md5" "$upload_file_md5";
            upload_aggregate_form_field "$upload_field_name.size" "$upload_file_size";
            upload_pass_form_field "^submit$|^description$";
            upload_cleanup 400 404 499 500-505;
        }

        # Additional configuration for serving static files.
        location / {    
            try_files $uri $uri/ =404;
        }      
    }

    # Additional route configurations can be added here
    # Additional configuration for handling other HTTP status codes.
}
